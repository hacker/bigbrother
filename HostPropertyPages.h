// HostPropertyPages.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHostPropertyPages

class CGeneralPage;
class CSettingsPage;
class CActionPage;
class CBrother;
class CBigBrotherView;
class CHostPropertyPages : public CPropertySheet
{
	DECLARE_DYNAMIC(CHostPropertyPages)

// Construction
public:
	CButton m_OK;
	CPoint m_InitialPosition;
	CBigBrotherView* m_Daddy;
	void UpdateBrother();
	CBrother* m_Brother;
	void SetBrother(CBrother* b);
	void CreatePages();
	CActionPage* m_Action;
	CSettingsPage* m_Settings;
	CGeneralPage* m_General;
	CHostPropertyPages(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CHostPropertyPages(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHostPropertyPages)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHostPropertyPages();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHostPropertyPages)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
