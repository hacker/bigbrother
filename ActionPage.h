// ActionPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CActionPage dialog

class CHostPropertyPages;
class CActionPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CActionPage)

// Construction
public:
	void BrowseCtl(CComboBox& ctl);
	HICON m_BrowseIcon;
	HICON m_PreplayIcon;
	void UpdateBrother();
	void UpdatePage();
	void SetupControls();
	CHostPropertyPages* m_dad;
	CActionPage();
	~CActionPage();

// Dialog Data
	//{{AFX_DATA(CActionPage)
	enum { IDD = IDD_PROPS_ACTION };
	CButton	m_BrowseUpCtl;
	CButton	m_BrowseDnCtl;
	CButton	m_SoundPreviewUp;
	CButton	m_SoundPreviewDn;
	CComboBox	m_SoundUpCtl;
	CComboBox	m_SoundDnCtl;
	CEdit	m_CustomUpCtl;
	CEdit	m_CustomDnCtl;
	CButton	m_bPlayASoundUpCtl;
	CButton	m_bPlayASoundDnCtl;
	CButton	m_OverrideActionCtl;
	CButton	m_bCustomUpCtl;
	CButton	m_bCustomDnCtl;
	BOOL	m_bCustomDn;
	BOOL	m_bCustomUp;
	BOOL	m_OverrideAction;
	BOOL	m_bPlayASoundDn;
	BOOL	m_bPlayASoundUp;
	CString	m_CustomDn;
	CString	m_CustomUp;
	CString	m_SoundDn;
	CString	m_SoundUp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CActionPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CActionPage)
	afx_msg void OnCustomDown();
	afx_msg void OnCustomUp();
	afx_msg void OnOverrideAction();
	afx_msg void OnPlayasoundDown();
	afx_msg void OnPlayasoundUp();
	afx_msg void OnPreviewSoundUp();
	afx_msg void OnPreviewSoundDown();
	afx_msg void OnBrowseSoundDown();
	afx_msg void OnBrowseSoundUp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
