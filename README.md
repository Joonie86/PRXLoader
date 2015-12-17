To add new plugins it is necessary to edit /dev_hdd0/game/PRXLOADER/USRDIR/plugins.txt 

-----------------------------------------------------------------------------------------------
Changes in VSH PRX Loader 1.13 (unofficial by Joonie): 

	* Added payload for  4.60DEH (DECR)
	
Changes in VSH PRX Loader 1.12 (unofficial by NzV): 

	* Added payload for  4.76CEX, 4.75DEX, 4.60DEX, 4.76DEX
	
Changes in VSH PRX Loader 1.11 (unofficial by NzV): 

	* Added payload for 4.75CEX
	
Changes in VSH PRX Loader 1.10 (unofficial by Joonie): 

	* Added payload for 4.70DEX

Changes in VSH PRX Loader 1.09 (unofficial by NzV): 

	* Added payload for 4.70CEX

	
Changes in VSH PRX Loader 1.08 (unofficial by NzV): 

	* Added payload for 3.55CEX, 4.30CEX, 4.30DEX, 4.31CEX, 4.40CEX, 4.41CEX, 4.41DEX, 4.53DEX , 4.66CEX, 4.66DEX
	* Payload modified (add get_vsh_process() in the payload instead of the loader)
	* Now if cobra/mamba is detected the payload will be no more installed, and the loader will use cobra/mamba syscall8 instead to load plugins
	* Add success/error ring buzzer notification
	[If buzzer ring one time cobra/mamba was detect and used to load plugins, if buzzer ring two times cobra/mamba was not detected so the payload was used to load plugins, if buzzer ring three times an error as occurred]

	
Changes in VSH PRX Loader 1.07 (unofficial by Joonie): 

	* Added payload for 4.65 dex by Joonie 
	* plugin's default path is now set to "dev_hdd0/game/PRXLOADER/USRDIR/plugins.txt" [it is the same as the original PRX loader by @user ] 
	-Due to various VSH plugin loader usages on various Cobra cfw builds, plugin path is changed back to the original- 

	
Changes in VSH PRX Loader 1.06 (unofficial by Joonie): 

	* Added payload for 4.65 cex by Joonie
	* plugin's default path is now set to "dev_hdd0/boot_plugins.txt" [it is the same as Cobra's CFW] 
	* 4.50 DEX support is fixed due to proper compilation 
	
	
Changes in VSH PRX Loader 1.05 (unofficial by Joonie): 

	* Added payload for 4.60 cex by Joonie 
	* Payload 4.50 dex is voided for the moment. 

	
Changes in VSH PRX Loader 1.04 (official by u$er): 

	* Added payload for 4.55 cex 
	* Added lv2 protection patch(4.46), so rebug users can skip the toolbox step 

	
Changes in VSH PRX Loader 1.03 (official by u$er): 

	* Added support for cfw 4.21 cex/dex and 4.53 cex (untested) 

	
Changes in VSH PRX Loader 1.02 (official by u$er): 

	* Fixed an issue on 4.46 CEX introduced in version 1.0 
