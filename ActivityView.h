// ActivityView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CActivityView view

class CBrother;
typedef	CTypedPtrList<CObList,CBrother*>	CBrotherList;
class CActivityView : public CScrollView
{
protected:
	CActivityView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CActivityView)

// Attributes
public:
	void UpdateTip(UINT nFlags,CPoint point);
	BOOL m_bPainted;
	CTimeSpan m_TimeSpan;
	CTime m_BeginTime;
	CToolTipCtrl m_ToolTip;
	COLORREF m_Background;
	CBrotherList *m_Brothers;
	void PaintHost(CBrother *b,CDC *pDC,CRect& rc,CTime* bTime=NULL,CTimeSpan* tSpan=NULL);
	COLORREF m_Dim;
	COLORREF m_Yellow;
	COLORREF m_Green;
	COLORREF m_Red;
	COLORREF m_BoxColor;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActivityView)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CActivityView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CActivityView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
