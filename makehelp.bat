@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by BIGBRO.HPJ. >"help\bigbro.hm"
echo. >>"help\bigbro.hm"
echo // Commands (ID_* and IDM_*) >>"help\bigbro.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"help\bigbro.hm"
echo. >>"help\bigbro.hm"
echo // Prompts (IDP_*) >>"help\bigbro.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"help\bigbro.hm"
echo. >>"help\bigbro.hm"
echo // Resources (IDR_*) >>"help\bigbro.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"help\bigbro.hm"
echo. >>"help\bigbro.hm"
echo // Dialogs (IDD_*) >>"help\bigbro.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"help\bigbro.hm"
echo. >>"help\bigbro.hm"
echo // Frame Controls (IDW_*) >>"help\bigbro.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"help\bigbro.hm"
REM -- Make help for Project BIGBROTHER


echo Building RTF file
xsltproc -o help/bigbrother.rtf shared-code/kinhelp.xsl help/bigbrother.xml
echo Building Win32 Help files
start /wait hcrtf -x "help\bigbrother.hpj"
echo.
if exist Debug\nul copy "help\bigbro.hlp" Debug
if exist Debug\nul copy "help\bigbro.cnt" Debug
if exist Release\nul copy "help\bigbro.hlp" Release
if exist Release\nul copy "help\bigbro.cnt" Release
if exist Releast\nul copy "help\bigbro.hlp" Releast
if exist Releast\nul copy "help\bigbro.cnt" Releast
echo.


