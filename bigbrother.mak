# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=install - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to install - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Big Brother - Win32 Release" && "$(CFG)" !=\
 "Big Brother - Win32 Debug" && "$(CFG)" != "Big Brother - Win32 Release Static"\
 && "$(CFG)" != "install - Win32 Debug" && "$(CFG)" != "install - Win32 Pure" &&\
 "$(CFG)" != "install - Win32 Canned" && "$(CFG)" != "install - Win32 Static"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "bigbrother.mak" CFG="install - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Big Brother - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Big Brother - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Big Brother - Win32 Release Static" (based on\
 "Win32 (x86) Application")
!MESSAGE "install - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "install - Win32 Pure" (based on "Win32 (x86) Application")
!MESSAGE "install - Win32 Canned" (based on "Win32 (x86) Application")
!MESSAGE "install - Win32 Static" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "install - Win32 Static"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Big Brother - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
TargetName=BigBro
# End Custom Macros

ALL : "$(OUTDIR)\BigBro.exe" "$(OUTDIR)\BigBro.ex_" "$(OUTDIR)\BigBro.hlp"\
 "$(OUTDIR)\BigBro.cnt" "$(OUTDIR)\BigBro.hl_" "$(OUTDIR)\BigBro.cn_"

CLEAN : 
	-@erase "$(INTDIR)\ActionPage.obj"
	-@erase "$(INTDIR)\ActivityView.obj"
	-@erase "$(INTDIR)\BigBro.cn_"
	-@erase "$(INTDIR)\BigBro.cnt"
	-@erase "$(INTDIR)\BigBro.hl_"
	-@erase "$(INTDIR)\BigBro.hlp"
	-@erase "$(INTDIR)\BigBrother.obj"
	-@erase "$(INTDIR)\bigbrother.pch"
	-@erase "$(INTDIR)\bigbrother.res"
	-@erase "$(INTDIR)\BigBrotherDoc.obj"
	-@erase "$(INTDIR)\BigBrotherView.obj"
	-@erase "$(INTDIR)\GeneralPage.obj"
	-@erase "$(INTDIR)\HostPropertyPages.obj"
	-@erase "$(INTDIR)\kICMP.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Preferences.obj"
	-@erase "$(INTDIR)\SettingsPage.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\BigBro.ex_"
	-@erase "$(OUTDIR)\BigBro.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/bigbrother.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/bigbrother.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/bigbrother.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release/BigBro.exe"
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/BigBro.pdb" /machine:I386 /out:"$(OUTDIR)/BigBro.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ActionPage.obj" \
	"$(INTDIR)\ActivityView.obj" \
	"$(INTDIR)\BigBrother.obj" \
	"$(INTDIR)\bigbrother.res" \
	"$(INTDIR)\BigBrotherDoc.obj" \
	"$(INTDIR)\BigBrotherView.obj" \
	"$(INTDIR)\GeneralPage.obj" \
	"$(INTDIR)\HostPropertyPages.obj" \
	"$(INTDIR)\kICMP.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Preferences.obj" \
	"$(INTDIR)\SettingsPage.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BigBro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetName=BigBro
InputPath=.\Release\BigBro.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
TargetName=BigBro
# End Custom Macros

ALL : "$(OUTDIR)\BigBro.exe" "$(OUTDIR)\bigbrother.bsc" "$(OUTDIR)\BigBro.hlp"\
 "$(OUTDIR)\BigBro.cnt" "$(OUTDIR)\BigBro.hl_" "$(OUTDIR)\BigBro.cn_"\
 "$(OUTDIR)\bigbro.ex_"

CLEAN : 
	-@erase "$(INTDIR)\ActionPage.obj"
	-@erase "$(INTDIR)\ActionPage.sbr"
	-@erase "$(INTDIR)\ActivityView.obj"
	-@erase "$(INTDIR)\ActivityView.sbr"
	-@erase "$(INTDIR)\BigBro.cn_"
	-@erase "$(INTDIR)\BigBro.cnt"
	-@erase "$(INTDIR)\BigBro.hl_"
	-@erase "$(INTDIR)\BigBro.hlp"
	-@erase "$(INTDIR)\BigBrother.obj"
	-@erase "$(INTDIR)\bigbrother.pch"
	-@erase "$(INTDIR)\bigbrother.res"
	-@erase "$(INTDIR)\BigBrother.sbr"
	-@erase "$(INTDIR)\BigBrotherDoc.obj"
	-@erase "$(INTDIR)\BigBrotherDoc.sbr"
	-@erase "$(INTDIR)\BigBrotherView.obj"
	-@erase "$(INTDIR)\BigBrotherView.sbr"
	-@erase "$(INTDIR)\GeneralPage.obj"
	-@erase "$(INTDIR)\GeneralPage.sbr"
	-@erase "$(INTDIR)\HostPropertyPages.obj"
	-@erase "$(INTDIR)\HostPropertyPages.sbr"
	-@erase "$(INTDIR)\kICMP.obj"
	-@erase "$(INTDIR)\kICMP.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\Preferences.obj"
	-@erase "$(INTDIR)\Preferences.sbr"
	-@erase "$(INTDIR)\SettingsPage.obj"
	-@erase "$(INTDIR)\SettingsPage.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\bigbro.ex_"
	-@erase "$(OUTDIR)\BigBro.exe"
	-@erase "$(OUTDIR)\BigBro.ilk"
	-@erase "$(OUTDIR)\BigBro.pdb"
	-@erase "$(OUTDIR)\bigbrother.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/bigbrother.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/bigbrother.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/bigbrother.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ActionPage.sbr" \
	"$(INTDIR)\ActivityView.sbr" \
	"$(INTDIR)\BigBrother.sbr" \
	"$(INTDIR)\BigBrotherDoc.sbr" \
	"$(INTDIR)\BigBrotherView.sbr" \
	"$(INTDIR)\GeneralPage.sbr" \
	"$(INTDIR)\HostPropertyPages.sbr" \
	"$(INTDIR)\kICMP.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\Preferences.sbr" \
	"$(INTDIR)\SettingsPage.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\bigbrother.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/BigBro.exe"
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/BigBro.pdb" /debug /machine:I386 /out:"$(OUTDIR)/BigBro.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ActionPage.obj" \
	"$(INTDIR)\ActivityView.obj" \
	"$(INTDIR)\BigBrother.obj" \
	"$(INTDIR)\bigbrother.res" \
	"$(INTDIR)\BigBrotherDoc.obj" \
	"$(INTDIR)\BigBrotherView.obj" \
	"$(INTDIR)\GeneralPage.obj" \
	"$(INTDIR)\HostPropertyPages.obj" \
	"$(INTDIR)\kICMP.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Preferences.obj" \
	"$(INTDIR)\SettingsPage.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BigBro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetName=BigBro
InputPath=.\Debug\BigBro.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BigBroth"
# PROP BASE Intermediate_Dir "BigBroth"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Releast"
# PROP Intermediate_Dir "Releast"
# PROP Target_Dir ""
OUTDIR=.\Releast
INTDIR=.\Releast
# Begin Custom Macros
OutDir=.\Releast
TargetName=BigBro
# End Custom Macros

ALL : "$(OUTDIR)\BigBro.exe" "$(OUTDIR)\BigBro.hlp" "$(OUTDIR)\BigBro.cnt"\
 "$(OUTDIR)\BigBro.hl_" "$(OUTDIR)\BigBro.cn_" "$(OUTDIR)\bigbro.ex_"

CLEAN : 
	-@erase "$(INTDIR)\ActionPage.obj"
	-@erase "$(INTDIR)\ActivityView.obj"
	-@erase "$(INTDIR)\BigBro.cn_"
	-@erase "$(INTDIR)\BigBro.cnt"
	-@erase "$(INTDIR)\BigBro.hl_"
	-@erase "$(INTDIR)\BigBro.hlp"
	-@erase "$(INTDIR)\BigBrother.obj"
	-@erase "$(INTDIR)\bigbrother.pch"
	-@erase "$(INTDIR)\bigbrother.res"
	-@erase "$(INTDIR)\BigBrotherDoc.obj"
	-@erase "$(INTDIR)\BigBrotherView.obj"
	-@erase "$(INTDIR)\GeneralPage.obj"
	-@erase "$(INTDIR)\HostPropertyPages.obj"
	-@erase "$(INTDIR)\kICMP.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Preferences.obj"
	-@erase "$(INTDIR)\SettingsPage.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\bigbro.ex_"
	-@erase "$(OUTDIR)\BigBro.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/bigbrother.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Releast/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/bigbrother.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/bigbrother.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Releast/BigBro.exe"
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/BigBro.pdb" /machine:I386 /out:"$(OUTDIR)/BigBro.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ActionPage.obj" \
	"$(INTDIR)\ActivityView.obj" \
	"$(INTDIR)\BigBrother.obj" \
	"$(INTDIR)\bigbrother.res" \
	"$(INTDIR)\BigBrotherDoc.obj" \
	"$(INTDIR)\BigBrotherView.obj" \
	"$(INTDIR)\GeneralPage.obj" \
	"$(INTDIR)\HostPropertyPages.obj" \
	"$(INTDIR)\kICMP.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Preferences.obj" \
	"$(INTDIR)\SettingsPage.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\BigBro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Releast
TargetName=BigBro
InputPath=.\Releast\BigBro.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "install - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "install\Debug"
# PROP BASE Intermediate_Dir "install\Debug"
# PROP BASE Target_Dir "install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "install\Debug"
# PROP Intermediate_Dir "install\Debug"
# PROP Target_Dir "install"
OUTDIR=.\install\Debug
INTDIR=.\install\Debug

ALL : "$(OUTDIR)\install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\install.res"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\install.exe"
	-@erase "$(OUTDIR)\install.ilk"
	-@erase "$(OUTDIR)\install.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/install.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\install\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/install.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/install.pdb" /debug /machine:I386 /out:"$(OUTDIR)/install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\install.res"

"$(OUTDIR)\install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "install - Win32 Pure"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "install\Pure"
# PROP BASE Intermediate_Dir "install\Pure"
# PROP BASE Target_Dir "install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "install\Pure"
# PROP Intermediate_Dir "install\Pure"
# PROP Target_Dir "install"
OUTDIR=.\install\Pure
INTDIR=.\install\Pure

ALL : "$(OUTDIR)\install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\install.res"
	-@erase "$(OUTDIR)\install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)/install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\install\Pure/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/install.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/install.pdb" /machine:I386 /out:"$(OUTDIR)/install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\install.res"

"$(OUTDIR)\install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "install - Win32 Canned"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "install\Canned"
# PROP BASE Intermediate_Dir "install\Canned"
# PROP BASE Target_Dir "install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "install\Canned"
# PROP Intermediate_Dir "install\Canned"
# PROP Target_Dir "install"
OUTDIR=.\install\Canned
INTDIR=.\install\Canned

ALL : "$(OUTDIR)\install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\install.res"
	-@erase "$(OUTDIR)\install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "K_ANNED" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "K_ANNED" /Fp"$(INTDIR)/install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\install\Canned/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "K_ANNED"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/install.res" /d "NDEBUG" /d "K_ANNED" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/install.pdb" /machine:I386 /out:"$(OUTDIR)/install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\install.res"

"$(OUTDIR)\install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "install - Win32 Static"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "install\Static"
# PROP BASE Intermediate_Dir "install\Static"
# PROP BASE Target_Dir "install"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "install\Static"
# PROP Intermediate_Dir "install\Static"
# PROP Target_Dir "install"
OUTDIR=.\install\Static
INTDIR=.\install\Static

ALL : "$(OUTDIR)\install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\install.res"
	-@erase "$(OUTDIR)\install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STATI_K" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STATI_K" /Fp"$(INTDIR)/install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\install\Static/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "STATI_K"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/install.res" /d "NDEBUG" /d "STATI_K" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib version.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/install.pdb" /machine:I386 /out:"$(OUTDIR)/install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\install.res"

"$(OUTDIR)\install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Big Brother - Win32 Release"
# Name "Big Brother - Win32 Debug"
# Name "Big Brother - Win32 Release Static"

!IF  "$(CFG)" == "Big Brother - Win32 Release"

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\BigBrother.cpp
DEP_CPP_BIGBR=\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\MainFrm.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\BigBrother.obj" : $(SOURCE) $(DEP_CPP_BIGBR) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\BigBrother.obj" : $(SOURCE) $(DEP_CPP_BIGBR) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\BigBrother.sbr" : $(SOURCE) $(DEP_CPP_BIGBR) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\BigBrother.obj" : $(SOURCE) $(DEP_CPP_BIGBR) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/bigbrother.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\bigbrother.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/bigbrother.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\StdAfx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\bigbrother.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/bigbrother.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\bigbrother.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\ActivityView.h"\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\HostPropertyPages.h"\
	".\MainFrm.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BigBrotherDoc.cpp
DEP_CPP_BIGBRO=\
	".\ActivityView.h"\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\HostPropertyPages.h"\
	".\MainFrm.h"\
	".\Preferences.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\BigBrotherDoc.obj" : $(SOURCE) $(DEP_CPP_BIGBRO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\BigBrotherDoc.obj" : $(SOURCE) $(DEP_CPP_BIGBRO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\BigBrotherDoc.sbr" : $(SOURCE) $(DEP_CPP_BIGBRO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\BigBrotherDoc.obj" : $(SOURCE) $(DEP_CPP_BIGBRO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BigBrotherView.cpp
DEP_CPP_BIGBROT=\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\HostPropertyPages.h"\
	".\MainFrm.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\BigBrotherView.obj" : $(SOURCE) $(DEP_CPP_BIGBROT) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\BigBrotherView.obj" : $(SOURCE) $(DEP_CPP_BIGBROT) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\BigBrotherView.sbr" : $(SOURCE) $(DEP_CPP_BIGBROT) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\BigBrotherView.obj" : $(SOURCE) $(DEP_CPP_BIGBROT) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\bigbrother.rc
DEP_RSC_BIGBROTH=\
	".\res\3angle.avi"\
	".\res\bigbrother.ico"\
	".\res\bigbrother.rc2"\
	".\res\BigBrotherDoc.ico"\
	".\res\goingdown.ico"\
	".\res\host-down.wav"\
	".\res\host-up.wav"\
	".\res\host.ico"\
	".\res\hostdown.ico"\
	".\res\junktoolbar.bmp"\
	".\res\maintoolbar.bmp"\
	".\res\nohost.ico"\
	".\res\pending.ico"\
	".\res\pinging.ico"\
	".\shared-data\browse-icon.ico"\
	".\shared-data\play-icon.ico"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\bigbrother.res" : $(SOURCE) $(DEP_RSC_BIGBROTH) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\bigbrother.res" : $(SOURCE) $(DEP_RSC_BIGBROTH) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\bigbrother.res" : $(SOURCE) $(DEP_RSC_BIGBROTH) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\GeneralPage.cpp
DEP_CPP_GENER=\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\GeneralPage.h"\
	".\HostPropertyPages.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\GeneralPage.obj" : $(SOURCE) $(DEP_CPP_GENER) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\GeneralPage.obj" : $(SOURCE) $(DEP_CPP_GENER) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\GeneralPage.sbr" : $(SOURCE) $(DEP_CPP_GENER) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\GeneralPage.obj" : $(SOURCE) $(DEP_CPP_GENER) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SettingsPage.cpp
DEP_CPP_SETTI=\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\HostPropertyPages.h"\
	".\SettingsPage.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\SettingsPage.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\SettingsPage.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\SettingsPage.sbr" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\SettingsPage.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\HostPropertyPages.cpp
DEP_CPP_HOSTP=\
	".\ActionPage.h"\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\GeneralPage.h"\
	".\HostPropertyPages.h"\
	".\SettingsPage.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\HostPropertyPages.obj" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\HostPropertyPages.obj" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\HostPropertyPages.sbr" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\HostPropertyPages.obj" : $(SOURCE) $(DEP_CPP_HOSTP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ActionPage.cpp
DEP_CPP_ACTIO=\
	".\ActionPage.h"\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\BigBrotherView.h"\
	".\HostPropertyPages.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\ActionPage.obj" : $(SOURCE) $(DEP_CPP_ACTIO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\ActionPage.obj" : $(SOURCE) $(DEP_CPP_ACTIO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\ActionPage.sbr" : $(SOURCE) $(DEP_CPP_ACTIO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\ActionPage.obj" : $(SOURCE) $(DEP_CPP_ACTIO) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ActivityView.cpp
DEP_CPP_ACTIV=\
	".\ActivityView.h"\
	".\bigbrother.h"\
	".\BigBrotherDoc.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\ActivityView.obj" : $(SOURCE) $(DEP_CPP_ACTIV) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\ActivityView.obj" : $(SOURCE) $(DEP_CPP_ACTIV) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\ActivityView.sbr" : $(SOURCE) $(DEP_CPP_ACTIV) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\ActivityView.obj" : $(SOURCE) $(DEP_CPP_ACTIV) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Preferences.cpp
DEP_CPP_PREFE=\
	".\bigbrother.h"\
	".\Preferences.h"\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"


"$(INTDIR)\Preferences.obj" : $(SOURCE) $(DEP_CPP_PREFE) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"


"$(INTDIR)\Preferences.obj" : $(SOURCE) $(DEP_CPP_PREFE) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"

"$(INTDIR)\Preferences.sbr" : $(SOURCE) $(DEP_CPP_PREFE) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"


"$(INTDIR)\Preferences.obj" : $(SOURCE) $(DEP_CPP_PREFE) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\help\bigbrother.hpj

!IF  "$(CFG)" == "Big Brother - Win32 Release"

# Begin Custom Build - Making help file..
OutDir=.\Release
ProjDir=.
TargetName=BigBro
InputPath=.\help\bigbrother.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"

# Begin Custom Build - Making help file..
OutDir=.\Debug
ProjDir=.
TargetName=BigBro
InputPath=.\help\bigbrother.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"

# Begin Custom Build - Making help file..
OutDir=.\Releast
ProjDir=.
TargetName=BigBro
InputPath=.\help\bigbrother.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=".\shared-code\kICMP.cpp"
DEP_CPP_KICMP=\
	".\shared-code\ip_icmp.h"\
	".\shared-code\kICMP.h"\
	".\shared-code\ms_icmp.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Big Brother - Win32 Release"

# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\kICMP.obj" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"
   $(CPP) /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/bigbrother.pch" /Yu"../stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Big Brother - Win32 Debug"

# ADD CPP /Yu"../stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/bigbrother.pch"\
 /Yu"../stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\kICMP.obj" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"
   $(BuildCmds)

"$(INTDIR)\kICMP.sbr" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Big Brother - Win32 Release Static"

# ADD BASE CPP /Yu"../stdafx.h"
# ADD CPP /Yu"../stdafx.h"

"$(INTDIR)\kICMP.obj" : $(SOURCE) $(DEP_CPP_KICMP) "$(INTDIR)"\
 "$(INTDIR)\bigbrother.pch"
   $(CPP) /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/bigbrother.pch" /Yu"../stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE)


!ENDIF 

# End Source File
# End Target
################################################################################
# Begin Target

# Name "install - Win32 Debug"
# Name "install - Win32 Pure"
# Name "install - Win32 Canned"
# Name "install - Win32 Static"

!IF  "$(CFG)" == "install - Win32 Debug"

!ELSEIF  "$(CFG)" == "install - Win32 Pure"

!ELSEIF  "$(CFG)" == "install - Win32 Canned"

!ELSEIF  "$(CFG)" == "install - Win32 Static"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\install\install.cpp
DEP_CPP_INSTA=\
	".\shared-code\install.h"\
	

!IF  "$(CFG)" == "install - Win32 Debug"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "install - Win32 Pure"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "install - Win32 Canned"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "install - Win32 Static"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\install\install.rc
DEP_RSC_INSTAL=\
	".\install\custom.rch"\
	".\shared-data\install-icon.ico"\
	

!IF  "$(CFG)" == "install - Win32 Debug"


"$(INTDIR)\install.res" : $(SOURCE) $(DEP_RSC_INSTAL) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/install.res" /i "install" /d "_DEBUG"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "install - Win32 Pure"


"$(INTDIR)\install.res" : $(SOURCE) $(DEP_RSC_INSTAL) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/install.res" /i "install" /d "NDEBUG"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "install - Win32 Canned"


"$(INTDIR)\install.res" : $(SOURCE) $(DEP_RSC_INSTAL) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/install.res" /i "install" /d "NDEBUG" /d\
 "K_ANNED" $(SOURCE)


!ELSEIF  "$(CFG)" == "install - Win32 Static"


"$(INTDIR)\install.res" : $(SOURCE) $(DEP_RSC_INSTAL) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/install.res" /i "install" /d "NDEBUG" /d\
 "STATI_K" $(SOURCE)


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
