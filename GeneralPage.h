// GeneralPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGeneralPage dialog

class CHostPropertyPages;
class CGeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGeneralPage)

// Construction
public:
	void SetupControls();
	void UpdateBrother();
	void UpdatePage();
	CHostPropertyPages* m_dad;
	CGeneralPage();
	~CGeneralPage();

// Dialog Data
	//{{AFX_DATA(CGeneralPage)
	enum { IDD = IDD_PROPS_GENERAL };
	CButton	m_LogActivityCtl;
	CEdit	m_HostCtl;
	CEdit	m_DescCtl;
	CString	m_Desc;
	CString	m_Host;
	int		m_LogActivity;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGeneralPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CGeneralPage)
	afx_msg void OnChangeHost();
	afx_msg void OnLogActivity();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
