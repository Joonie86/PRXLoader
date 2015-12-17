@echo off

set PS3DEV=./ps3dev
set PS3SDK=/c/PSDK3v2
set WIN_PS3SDK=C:/PSDK3v2
set PATH=%WIN_PS3SDK%/mingw/msys/1.0/bin;%WIN_PS3SDK%/mingw/bin;%PS3DEV%/ppu/bin;

rem %PATH%;

if exist payload del payload\*.bin>nul
if exist payload rmdir payload

del *.bin>nul

make clean

make all

if not exist payload mkdir payload

if exist payload_3_55.bin     move  payload_3_55.bin     payload\payload_355C.bin>nul
if exist payload_3_55DEX.bin  move  payload_3_55DEX.bin  payload\payload_355D.bin>nul
if exist payload_4_21.bin     move  payload_4_21.bin     payload\payload_421C.bin>nul
if exist payload_4_21DEX.bin  move  payload_4_21DEX.bin  payload\payload_421D.bin>nul
if exist payload_4_30.bin     move  payload_4_30.bin     payload\payload_430C.bin>nul
if exist payload_4_30DEX.bin  move  payload_4_30DEX.bin  payload\payload_430D.bin>nul
if exist payload_4_31.bin     move  payload_4_31.bin     payload\payload_431C.bin>nul
if exist payload_4_40.bin     move  payload_4_40.bin     payload\payload_440C.bin>nul
if exist payload_4_41.bin     move  payload_4_41.bin     payload\payload_441C.bin>nul
if exist payload_4_41DEX.bin  move  payload_4_41DEX.bin  payload\payload_441D.bin>nul
if exist payload_4_46.bin     move  payload_4_46.bin     payload\payload_446C.bin>nul
if exist payload_4_46DEX.bin  move  payload_4_46DEX.bin  payload\payload_446D.bin>nul
if exist payload_4_50.bin     move  payload_4_50.bin     payload\payload_450C.bin>nul
if exist payload_4_50DEX.bin  move  payload_4_50DEX.bin  payload\payload_450D.bin>nul
if exist payload_4_53.bin     move  payload_4_53.bin     payload\payload_453C.bin>nul
if exist payload_4_53DEX.bin  move  payload_4_53DEX.bin  payload\payload_453D.bin>nul
if exist payload_4_55.bin     move  payload_4_55.bin     payload\payload_455C.bin>nul
if exist payload_4_55DEX.bin  move  payload_4_55DEX.bin  payload\payload_455D.bin>nul
if exist payload_4_60.bin     move  payload_4_60.bin     payload\payload_460C.bin>nul
if exist payload_4_60DEX.bin  move  payload_4_60DEX.bin  payload\payload_460D.bin>nul
if exist payload_4_60DEH.bin  move  payload_4_60DEH.bin  payload\payload_460E.bin>nul
if exist payload_4_65.bin     move  payload_4_65.bin     payload\payload_465C.bin>nul
if exist payload_4_65DEX.bin  move  payload_4_65DEX.bin  payload\payload_465D.bin>nul
if exist payload_4_66.bin     move  payload_4_66.bin     payload\payload_466C.bin>nul
if exist payload_4_66DEX.bin  move  payload_4_66DEX.bin  payload\payload_466D.bin>nul
if exist payload_4_70.bin     move  payload_4_70.bin     payload\payload_470C.bin>nul
if exist payload_4_70DEX.bin  move  payload_4_70DEX.bin  payload\payload_470D.bin>nul
if exist payload_4_75.bin     move  payload_4_75.bin     payload\payload_475C.bin>nul
if exist payload_4_75DEX.bin  move  payload_4_75DEX.bin  payload\payload_475D.bin>nul
if exist payload_4_76.bin     move  payload_4_76.bin     payload\payload_476C.bin>nul
if exist payload_4_76DEX.bin  move  payload_4_76DEX.bin  payload\payload_476D.bin>nul


:copy *.bin ..\datas\*

pause
