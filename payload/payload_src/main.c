#include <lv2/lv2.h>
#include <lv2/libc.h>
#include <lv2/memory.h>
#include <lv2/syscall.h>
#include <lv2/thread.h>
#include <lv2/process.h>
#include <lv2/modules.h>
#include <lv2/error.h>
#include <lv2/symbols.h>

#define SYSCALL1022_OPCODE_LOAD_VSH_PLUGIN			0x1EE7
#define SYSCALL1022_OPCODE_UNLOAD_VSH_PLUGIN		0x364F

#define MAX_VSH_PLUGINS		6

sys_prx_id_t vsh_plugins[MAX_VSH_PLUGINS];

process_t get_vsh_process(void)
{
	uint64_t *proc_list = *(uint64_t **)MKA(TOC+process_rtoc_entry_1);	
	proc_list = *(uint64_t **)proc_list;
	proc_list = *(uint64_t **)proc_list;	
	for (int i = 0; i < 16; i++)
	{
		process_t p = (process_t)proc_list[1];	
		proc_list += 2;		
		if ((((uint64_t)p) & 0xFFFFFFFF00000000ULL) != MKA(0)) continue;
		if (is_vsh_process(p)) return p;
	}
	return 0;
}

int sys_prx_load_vsh_plugin(unsigned int slot, char *path, void *arg, uint32_t arg_size)
{
	process_t vsh_process = get_vsh_process();
	if (!vsh_process) return -1;
	void *kbuf, *vbuf;
	sys_prx_id_t prx;
	int ret;
	path = get_secure_user_ptr(path);
	arg = get_secure_user_ptr(arg);
	if (slot >= MAX_VSH_PLUGINS || (arg != NULL && arg_size > KB(64))) return EINVAL;
	if (vsh_plugins[slot] != 0) return EKRESOURCE;
	prx = prx_load_module(vsh_process, 0, 0, path);
	if (prx < 0) return prx;
	if (arg && arg_size > 0)
	{
		page_allocate_auto(vsh_process, KB(64), 0x2F, &kbuf);
		page_export_to_proc(vsh_process, kbuf, 0x40000, &vbuf);
		copy_from_user(arg, kbuf, arg_size);
	}
	else vbuf = NULL;
	ret = prx_start_module_with_thread(prx, vsh_process, 0, (uint64_t)vbuf);
	if (vbuf)
	{
		page_unexport_from_proc(vsh_process, vbuf);
		page_free(vsh_process, kbuf, 0x2F);
	}
	if (ret == 0) vsh_plugins[slot] = prx;
	else
	{
		prx_stop_module_with_thread(prx, vsh_process, 0, 0);
		prx_unload_module(prx, vsh_process);
	}
	return ret;
}

int sys_prx_unload_vsh_plugin(unsigned int slot)
{
	process_t vsh_process = get_vsh_process();
	if (!vsh_process) return -1;
	int ret;
	sys_prx_id_t prx;
	if (slot >= MAX_VSH_PLUGINS) return EINVAL;
	prx = vsh_plugins[slot];
	if (prx == 0)return ENOENT;
	ret = prx_stop_module_with_thread(prx, vsh_process, 0, 0);
	if (ret == 0) ret = prx_unload_module(prx, vsh_process);
	if (ret == 0) vsh_plugins[slot] = 0;
	return ret;
}

int syscall1022(uint64_t function, uint64_t param1, uint64_t param2, uint64_t param3, uint64_t param4, uint64_t param5, uint64_t param6, uint64_t param7)
{
	extend_kstack(0);
	switch (function)
	{
		case SYSCALL1022_OPCODE_LOAD_VSH_PLUGIN:
			return sys_prx_load_vsh_plugin((unsigned int)param1, (char *)param2, (void *)param3, (uint32_t)param4);
		break;

		case SYSCALL1022_OPCODE_UNLOAD_VSH_PLUGIN:
			return sys_prx_unload_vsh_plugin((unsigned int)param1);
		break;
	}
	return ENOSYS;
}


