; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPreferences
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BigBrother.h"
LastPage=0

ClassCount=11
Class1=CBigBrotherApp
Class2=CBigBrotherDoc
Class3=CBigBrotherView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_PREFS
Resource2=IDD_PROPS_SETTINGS
Class5=CAboutDlg
Resource3=IDM_POPUPS
Class6=CGeneralPage
Class7=CSettingsPage
Class8=CHostPropertyPages
Resource4=IDR_JUNKTOOLBAR
Class9=CActionPage
Class10=CActivityView
Resource5=IDD_PROPS_GENERAL
Resource6=IDR_JUNKACCELERATOR
Resource7=IDD_PROPS_ACTION
Resource8=IDD_ABOUTBOX
Class11=CPreferences
Resource9=IDR_MAINFRAME

[CLS:CBigBrotherApp]
Type=0
HeaderFile=BigBrother.h
ImplementationFile=BigBrother.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=ID_HELP_LEGEND

[CLS:CBigBrotherDoc]
Type=0
HeaderFile=BigBrotherDoc.h
ImplementationFile=BigBrotherDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_VIEW_HOSTPROPERTIES

[CLS:CBigBrotherView]
Type=0
HeaderFile=BigBrotherView.h
ImplementationFile=BigBrotherView.cpp
Filter=C
LastObject=CBigBrotherView
BaseClass=CTreeView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=BigBrother.cpp
ImplementationFile=BigBrother.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_KLEVERNET,button,1342242816

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_AUTOLOAD
Command6=ID_FILE_PREFERENCES
Command7=ID_FILE_PAUSE
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_BROTHERS_NEW
Command11=ID_BROTHERS_ADDBROTHER
Command12=ID_BROTHERS_DELETE
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_WINDOW_SPLIT
Command16=ID_VIEW_MAINWINDOW
Command17=ID_VIEW_HOSTPROPERTIES
Command18=ID_HELP_FINDER
Command19=ID_HELP_LEGEND
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PREFERENCES
Command4=ID_FILE_SAVE
Command5=ID_BROTHERS_DELETE
Command6=ID_BROTHERS_DELETE
Command7=ID_HELP
Command8=ID_CONTEXT_HELP
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_BROTHERS_NEW
Command12=ID_APP_EXIT
CommandCount=12

[DLG:IDD_PROPS_SETTINGS]
Type=1
Class=CSettingsPage
ControlCount=10
Control1=IDC_STATIC,button,1342193671
Control2=IDC_OVERRIDE_INTERVALS,button,1342242819
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PINGINTERVAL_GOOD,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PINGINTERVAL_BAD,edit,1350631552
Control7=IDC_OVERRIDE_TIMEOUT,button,1342242819
Control8=IDC_PINGTIMEOUT,edit,1350631552
Control9=IDC_OVERRIDE_RETRIES,button,1342242819
Control10=IDC_RETRIES,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_BROTHERS_NEW
Command5=ID_BROTHERS_ADDBROTHER
Command6=ID_BROTHERS_DELETE
Command7=ID_VIEW_HOSTPROPERTIES
Command8=ID_FILE_PAUSE
Command9=ID_APP_ABOUT
Command10=ID_CONTEXT_HELP
Command11=ID_HELP_LEGEND
CommandCount=11

[DLG:IDD_PROPS_GENERAL]
Type=1
Class=CGeneralPage
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_HOST,edit,1350631568
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DESC,edit,1350631552
Control5=IDC_LOG_ACTIVITY,button,1342246918

[CLS:CGeneralPage]
Type=0
HeaderFile=GeneralPage.h
ImplementationFile=GeneralPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CGeneralPage
VirtualFilter=idWC

[CLS:CSettingsPage]
Type=0
HeaderFile=SettingsPage.h
ImplementationFile=SettingsPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CSettingsPage
VirtualFilter=idWC

[CLS:CHostPropertyPages]
Type=0
HeaderFile=HostPropertyPages.h
ImplementationFile=HostPropertyPages.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CHostPropertyPages
VirtualFilter=hWC

[DLG:IDD_PROPS_ACTION]
Type=1
Class=CActionPage
ControlCount=15
Control1=IDC_OVERRIDE_ACTION,button,1342246915
Control2=IDC_STATIC,button,1342177287
Control3=IDC_PLAYASOUND_DOWN,button,1342242819
Control4=IDC_SOUND_DOWN,combobox,1344340034
Control5=IDC_BROWSE_SOUND_DOWN,button,1342263104
Control6=IDC_PREVIEW_SOUND_DOWN,button,1342263104
Control7=IDC_CUSTOM_DOWN,button,1342242819
Control8=IDC_PROGRAM_DOWN,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_PLAYASOUND_UP,button,1342242819
Control11=IDC_SOUND_UP,combobox,1344340034
Control12=IDC_BROWSE_SOUND_UP,button,1342263104
Control13=IDC_PREVIEW_SOUND_UP,button,1342263104
Control14=IDC_CUSTOM_UP,button,1342242819
Control15=IDC_PROGRAM_UP,edit,1350631552

[CLS:CActionPage]
Type=0
HeaderFile=ActionPage.h
ImplementationFile=ActionPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CActionPage
VirtualFilter=idWC

[CLS:CActivityView]
Type=0
HeaderFile=ActivityView.h
ImplementationFile=ActivityView.cpp
BaseClass=CScrollView
Filter=C
LastObject=CActivityView
VirtualFilter=VWC

[MNU:IDM_POPUPS]
Type=1
Command1=ID_VIEW_MAINWINDOW
Command2=ID_HELP_FINDER
Command3=ID_APP_ABOUT
Command4=ID_APP_EXIT
Command5=ID_INDICATOR_PINGBAR
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_FILE_PRINT
Command11=ID_FILE_PRINT_PREVIEW
Command12=ID_FILE_PRINT_SETUP
CommandCount=12

[ACL:IDR_JUNKACCELERATOR]
Type=1
Command1=ID_EDIT_COPY
Command2=ID_FILE_PRINT
Command3=ID_EDIT_PASTE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_CUT
Command9=ID_EDIT_UNDO
CommandCount=9

[TB:IDR_JUNKTOOLBAR]
Type=1
Command1=ID_FILE_PRINT
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
CommandCount=4

[DLG:IDD_PREFS]
Type=1
Class=CPreferences
ControlCount=26
Control1=IDC_STATIC,button,1342177287
Control2=IDC_SAVEONSHUTDOWN,button,1342268163
Control3=IDC_STATIC,static,1342308352
Control4=IDC_AUTOSAVEMINS,edit,1350631552
Control5=IDC_AUTOSPIN,msctls_updown32,1342177463
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308608
Control9=IDC_PINGSIZE,edit,1350631552
Control10=IDC_DATASIZESPIN,msctls_updown32,1342177463
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_MAXTHREADS,edit,1350631552
Control14=IDC_THREADSPIN,msctls_updown32,1342177463
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308352
Control18=IDC_LOGFILE,edit,1350631552
Control19=IDC_BROWSE,button,1342263104
Control20=IDC_STATIC,static,1342308352
Control21=IDC_LOGMINS,edit,1350631552
Control22=IDC_LOGMINSPIN,msctls_updown32,1342177463
Control23=IDC_STATIC,static,1342308608
Control24=IDOK,button,1342242817
Control25=IDCANCEL,button,1342242816
Control26=IDC_STOREACTIVITY,button,1342242819

[CLS:CPreferences]
Type=0
HeaderFile=Preferences.h
ImplementationFile=Preferences.cpp
BaseClass=CDialog
Filter=D
LastObject=CPreferences
VirtualFilter=dWC

