// SettingsPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingsPage dialog

class CHostPropertyPages;
class CSettingsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSettingsPage)

// Construction
public:
	void UpdateBrother();
	void UpdatePage();
	void SetupControls();
	CHostPropertyPages* m_dad;
	CSettingsPage();
	~CSettingsPage();

// Dialog Data
	//{{AFX_DATA(CSettingsPage)
	enum { IDD = IDD_PROPS_SETTINGS };
	CEdit	m_RetriesCtl;
	CEdit	m_TimeOutCtl;
	CEdit	m_IntervalGoodCtl;
	CEdit	m_IntervalBadCtl;
	CButton	m_OverrideTimeoutCtl;
	CButton	m_OverrideRetriesCtl;
	CButton	m_OverrideIntervalsCtl;
	BOOL	m_OverrideIntervals;
	BOOL	m_OverrideRetries;
	BOOL	m_OverrideTimeout;
	DWORD	m_IntervalBad;
	DWORD	m_IntervalGood;
	DWORD	m_TimeOut;
	UINT	m_Retries;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSettingsPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSettingsPage)
	afx_msg void OnOverrideIntervals();
	afx_msg void OnOverrideRetries();
	afx_msg void OnOverrideTimeout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
