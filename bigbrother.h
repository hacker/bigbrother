// BigBrother.h : main header file for the BIGBROTHER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherApp:
// See BigBrother.cpp for the implementation of this class
//

class CBigBrotherApp : public CWinApp
{
public:
	BOOL m_bLoadMRUOnStartup;
	CBigBrotherApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBigBrotherApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBigBrotherApp)
	afx_msg void OnAppAbout();
	afx_msg void OnUpdateFileAutoload(CCmdUI* pCmdUI);
	afx_msg void OnFileAutoload();
	afx_msg void OnHelpLegend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
