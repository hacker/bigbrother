// Preferences.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog

class CPreferences : public CDialog
{
// Construction
public:
	CPreferences(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreferences)
	enum { IDD = IDD_PREFS };
	CSpinButtonCtrl	m_LogMinSpinCtl;
	CEdit	m_LogFileCtl;
	CSpinButtonCtrl	m_ThreadsSpinCtl;
	CSpinButtonCtrl	m_DatasizeSpinCtl;
	CButton	m_BrowseCtl;
	CSpinButtonCtrl	m_AutosaveSpinCtl;
	UINT	m_AutosaveMinutes;
	CString	m_LogFile;
	UINT	m_MaxThreads;
	UINT	m_PingSize;
	BOOL	m_SaveOnShutdown;
	UINT	m_LogMins;
	BOOL	m_bStoreLastActivity;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreferences)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreferences)
	virtual BOOL OnInitDialog();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
