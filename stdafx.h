// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcview.h>
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows 95 Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions

#include <afxtempl.h>

#include <winsock.h>
#include "shared-code/ms_icmp.h"
#include "shared-code/ip_icmp.h"
#include "shared-code/kICMP.h"

enum	{
	WM_TRAYICONMESSAGE = WM_USER,
	WM_ACTIVITYCOUNT,
	WM_UPDATETREEBROTHER,
	WM_CHECKQUEUE,
	WM_BROTHERUPDOWN
};
#include <MMSystem.h>
// CG: The following line was added by the Windows Multimedia component.
#pragma comment(lib, "winmm.lib")
