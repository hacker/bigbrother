// BigBrotherView.h : interface of the CBigBrotherView class
//
/////////////////////////////////////////////////////////////////////////////

class CHostPropertyPages;
class CBrother;
class CBigBrotherDoc;
typedef	CTypedPtrList<CObList,CBrother*>	CBrotherList;
class CBigBrotherView : public CTreeView
{
protected: // create from serialization only
	CBigBrotherView();
	DECLARE_DYNCREATE(CBigBrotherView)

// Attributes
public:
	void SetupExpansion(CBrother *b);
	void KillOneBrother(CBrother *b);
	void KillBrother(CBrother *b);
	void ContextMenu(CPoint pt);
	void GetFamily(CBrother* b,CBrotherList* bh);
	int m_iPinging;
	int m_iPending;
	int m_iHostDown;
	int m_iGoingDown;
	int m_iHost;
	int m_iNoHost;
	CImageList m_Images;
	void UpdateBrother(CBrother* b);
	void GotoBrother(CBrother *b);
	void AddBrother(CBrother *b);
	CBrother* GetCurrentBrother();
	HTREEITEM FindItem(CBrother* brother);
	CHostPropertyPages* m_Pages;
	CBigBrotherDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBigBrotherView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBigBrotherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBigBrotherView)
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReturn(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnActivityCount(WPARAM,LPARAM);
	afx_msg LRESULT OnUpdateTreeBrother(WPARAM,LPARAM);
	afx_msg LRESULT OnCheckQueue(WPARAM,LPARAM);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnUpDown(WPARAM,LPARAM);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BigBrotherView.cpp
inline CBigBrotherDoc* CBigBrotherView::GetDocument()
   { return (CBigBrotherDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
