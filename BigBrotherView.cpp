// BigBrotherView.cpp : implementation of the CBigBrotherView class
//

#include "stdafx.h"
#include "BigBrother.h"

#include "BigBrotherDoc.h"
#include "BigBrotherView.h"
#include "HostPropertyPages.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherView

IMPLEMENT_DYNCREATE(CBigBrotherView, CTreeView)

BEGIN_MESSAGE_MAP(CBigBrotherView, CTreeView)
	//{{AFX_MSG_MAP(CBigBrotherView)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(NM_RETURN, OnReturn)
	ON_MESSAGE(WM_ACTIVITYCOUNT, OnActivityCount)
	ON_MESSAGE(WM_UPDATETREEBROTHER, OnUpdateTreeBrother)
	ON_MESSAGE(WM_CHECKQUEUE, OnCheckQueue)
	ON_WM_TIMER()
	ON_WM_CONTEXTMENU()
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_WM_CHAR()
	ON_MESSAGE(WM_BROTHERUPDOWN, OnUpDown)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherView construction/destruction

CBigBrotherView::CBigBrotherView()
	: m_Pages(NULL)
{
	// Load Images
	m_Images.Create(16,16,TRUE,5,2);
CWinApp *app=AfxGetApp();
	VERIFY((m_iNoHost=m_Images.Add(app->LoadIcon(IDI_NOHOST)))>=0);
	VERIFY((m_iHost=m_Images.Add(app->LoadIcon(IDI_HOST)))>=0);
	VERIFY((m_iGoingDown=m_Images.Add(app->LoadIcon(IDI_GOINGDOWN)))>=0);
	VERIFY((m_iHostDown=m_Images.Add(app->LoadIcon(IDI_HOSTDOWN)))>=0);
	VERIFY((m_iPending=m_Images.Add(app->LoadIcon(IDI_PENDING)))>=0);
	VERIFY((m_iPinging=m_Images.Add(app->LoadIcon(IDI_PINGING)))>=0);
}

CBigBrotherView::~CBigBrotherView()
{
}

BOOL CBigBrotherView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherView drawing

void CBigBrotherView::OnDraw(CDC* pDC)
{
	CBigBrotherDoc* pDoc = GetDocument();
	ASSERT(pDoc);
	ASSERT_VALID(pDoc);
}

void CBigBrotherView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

CWinApp *app=AfxGetApp();
	ASSERT(app);
CTreeCtrl& ctl = GetTreeCtrl();
CBigBrotherDoc* doc = GetDocument();
	ASSERT(doc);
	ctl.SetImageList(&m_Images,TVSIL_NORMAL);
	ctl.ModifyStyle(0,TVS_LINESATROOT|TVS_HASLINES|TVS_HASBUTTONS);
	ctl.DeleteAllItems();
POSITION p = doc->m_Brotherhood.GetHeadPosition();
	VERIFY(doc->m_RootBrother);
	AddBrother(doc->m_RootBrother);
	while(p){
	CBrother *b = (CBrother*)doc->m_Brotherhood.GetNext(p);
		ASSERT(b->m_Daddy);
		AddBrother(b);
	}
	SetupExpansion(doc->m_RootBrother);
	doc->UpdateAllViews(this);
CRect rc;
	GetClientRect(rc);
	ClientToScreen(rc);
CRect prc;
	m_Pages->GetWindowRect(prc);
CRect nrc;
	if(m_Pages->m_InitialPosition.x<0 || m_Pages->m_InitialPosition.y<0){
		nrc.bottom=rc.bottom; nrc.right=rc.right;
		nrc.top=nrc.bottom-prc.Height(); nrc.left=nrc.right-prc.Width();
	}else{
		nrc.left=m_Pages->m_InitialPosition.x;nrc.top=m_Pages->m_InitialPosition.y;
		nrc.right=nrc.left+prc.Width(); nrc.bottom=nrc.top+prc.Height();
	}
	m_Pages->MoveWindow(nrc,FALSE);
	m_Pages->ShowWindow((doc->flags&CBigBrotherDoc::flagsShowProps)?SW_SHOW:SW_HIDE);
}

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherView printing

BOOL CBigBrotherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBigBrotherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CBigBrotherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherView diagnostics

#ifdef _DEBUG
void CBigBrotherView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CBigBrotherView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CBigBrotherDoc* CBigBrotherView::GetDocument() // non-debug version is inline
{
	if(m_pDocument)
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
	return (CBigBrotherDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherView message handlers

void CBigBrotherView::OnDestroy() 
{
	CTreeView::OnDestroy();
	
	if(m_Pages){
		m_Pages->DestroyWindow();
		delete m_Pages;
		m_Pages=NULL;
	}
}

int CBigBrotherView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_Pages = new CHostPropertyPages(IDS_PROPS_TITLE);
	m_Pages->m_Daddy=this;
	m_Pages->Create(this,WS_POPUP||WS_CLIPSIBLINGS|WS_BORDER|WS_DLGFRAME,WS_EX_TOOLWINDOW|WS_EX_WINDOWEDGE);
	
	return 0;
}

HTREEITEM CBigBrotherView::FindItem(CBrother* brother)
{
DWORD b = (DWORD)brother;
CTreeCtrl& ctl = GetTreeCtrl();
HTREEITEM rv = ctl.GetRootItem();
	ASSERT(rv);
	do{
		if(ctl.GetItemData(rv)==b)
			return rv;
	}while((rv=ctl.GetNextItem(rv,TVGN_NEXT)));
	ASSERT(0);
	return NULL;
}

CBrother* CBigBrotherView::GetCurrentBrother()
{
HTREEITEM	hItem = GetTreeCtrl().GetSelectedItem();
	if(!hItem)
		return NULL;
CBrother *rv = (CBrother*)GetTreeCtrl().GetItemData(hItem);
	ASSERT(rv);
	return rv;
}

void CBigBrotherView::AddBrother(CBrother *b)
{
HTREEITEM hDaddy=TVI_ROOT;
	if(b->m_Daddy){
		ASSERT(b->m_Daddy->m_Item);
		hDaddy=b->m_Daddy->m_Item;
	}
CString tmp;
	tmp=b->m_Desc;
	if(tmp.IsEmpty())
		tmp.LoadString(IDS_NODESC);
	b->AppendSeparator();
	b->m_Item=GetTreeCtrl().InsertItem(TVIF_PARAM|TVIF_TEXT,tmp,0,0,0,0,(LPARAM)b,hDaddy,TVI_LAST);
	ASSERT(b->m_Item);
	UpdateBrother(b);
}

void CBigBrotherView::GotoBrother(CBrother *b)
{
	ASSERT(b->m_Item);
	GetTreeCtrl().SelectItem(b->m_Item);
}

void CBigBrotherView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	m_Pages->SetBrother(GetCurrentBrother());
CBigBrotherDoc *pDoc = GetDocument();
	if(pDoc)
		pDoc->UpdateAllViews(this);
	*pResult = 0;
}

void CBigBrotherView::UpdateBrother(CBrother* b)
{
	if(!b->m_Item)
		return;
	ASSERT(b->m_Item);
CString tmp;
	tmp=b->m_Desc;
	if(tmp.IsEmpty())
		tmp.LoadString(IDS_NODESC);
	GetTreeCtrl().SetItemText(b->m_Item,tmp);
int	image = m_iNoHost;
	if(!b->m_Host.IsEmpty()){
		if(b->m_bPending)
			image = m_iPending;
		else if(b->m_bPinging)
			image=m_iPinging;
		else if(b->m_bPinged){
			if(b->m_bIsUp){
				image=m_iHost;
				if(!b->m_bUp){
					PostMessage(WM_BROTHERUPDOWN,TRUE,(LPARAM)b);
					b->m_bUp=TRUE;
				}
			}else{
				if(b->m_HowDown>=b->m_Retries){
					image=m_iHostDown;
					if(b->m_bUp){
						PostMessage(WM_BROTHERUPDOWN,FALSE,(LPARAM)b);
						b->m_bUp=FALSE;
					}
				}else
					image=m_iGoingDown;
				b->m_HowDown=min(b->m_HowDown,b->m_Retries+1);
			}
		}else
			image=m_iHost;
	}
	GetTreeCtrl().SetItemImage(b->m_Item,image,image);
	PostMessage(WM_CHECKQUEUE);
}

void CBigBrotherView::OnReturn(NMHDR* pNMHDR, LRESULT* pResult) 
{
CBigBrotherDoc *pDoc = GetDocument();
	ASSERT(pDoc);
	pDoc->flags|=CBigBrotherDoc::flagsShowProps;
	m_Pages->ShowWindow(SW_SHOW);
	m_Pages->SetFocus();
	*pResult = 0;
}

LRESULT CBigBrotherView::OnActivityCount(WPARAM wP,LPARAM)
{
CMainFrame *mf = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	ASSERT(mf);
	ASSERT(mf->IsKindOf(RUNTIME_CLASS(CMainFrame)));
int crement = (int)wP;
CBigBrotherDoc *doc = GetDocument();
	ASSERT(doc);
	ASSERT(doc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
	doc->m_Threads+=crement;
	if(doc->m_Threads<0)
		doc->m_Threads=0;
	if(doc->m_Threads){
		mf->m_PingBar.Play(0,(UINT)-1,(UINT)-1);
	}else{
		mf->m_PingBar.Stop();
		mf->m_PingBar.Seek(0);
	}
	if(crement<0)
		PostMessage(WM_CHECKQUEUE);
	return doc->m_Threads;
}

LRESULT CBigBrotherView::OnUpdateTreeBrother(WPARAM wP,LPARAM lP)
{
CBrother *b = (CBrother*)lP;
	ASSERT(b);
	if(wP)
		b->m_bPinging=FALSE;
	UpdateBrother(b);
CBigBrotherDoc *pDoc = GetDocument();
	if(pDoc)
		pDoc->UpdateAllViews(this,0,b);
	return 0;
}

LRESULT CBigBrotherView::OnCheckQueue(WPARAM,LPARAM)
{
CBigBrotherDoc *doc = GetDocument();
	if(doc)
		doc->CheckPendingQueue();
	return 0;
}

void CBigBrotherView::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent){
	case TM_CHECK:
		KillTimer(TM_CHECK);
		PostMessage(WM_CHECKQUEUE);
		break;
	}
	CTreeView::OnTimer(nIDEvent);
}

void CBigBrotherView::GetFamily(CBrother* b,CBrotherList* bh)
{
	if(b->IsValuable())
		bh->AddTail(b);
	ASSERT(b->m_Item);
CTreeCtrl& ctl = GetTreeCtrl();
	if(!(ctl.GetItemState(b->m_Item,TVIS_EXPANDED)&TVIS_EXPANDED))
		return;
HTREEITEM hItem = ctl.GetNextItem(b->m_Item,TVGN_CHILD);
	while(hItem){
	CBrother *bb = (CBrother*)ctl.GetItemData(hItem);
		ASSERT(bb);
		GetFamily(bb,bh);
		hItem = ctl.GetNextItem(hItem,TVGN_NEXT);
	}
}

void CBigBrotherView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	if(point.x<0 || point.y<0){
	CBrother *b = GetCurrentBrother();
		ASSERT(b);
	CRect rc;
		GetTreeCtrl().GetItemRect(b->m_Item,&rc,TRUE);
		point = rc.TopLeft();
		ClientToScreen(&point);
	}
	ContextMenu(point);
}

void CBigBrotherView::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
CPoint pt;
	VERIFY(GetCursorPos(&pt));
	ContextMenu(pt);
	*pResult = 0;
}

void CBigBrotherView::ContextMenu(CPoint pt)
{
CMenu m;
	VERIFY(m.LoadMenu(IDR_MAINFRAME));
CMenu *popUp = m.GetSubMenu(1);	// Brothers
	ASSERT(popUp);
	popUp->TrackPopupMenu(TPM_CENTERALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,pt.x,pt.y,AfxGetApp()->m_pMainWnd);
}

void CBigBrotherView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
}

LRESULT CBigBrotherView::OnUpDown(WPARAM wP,LPARAM lP)
{
BOOL isUp = (BOOL)wP;
CBrother *b = (CBrother*)lP;
	ASSERT(b);
UINT	strResource;
	b->ParentalAdjust();
	if(isUp){
		b->m_Up.PerformAction(b);
		strResource = IDS_LOG_HOSTUP;
	}else{
		b->m_Down.PerformAction(b);
		strResource = IDS_LOG_HOSTDOWN;
	}
CString logLine;
	logLine.Format(strResource,(LPCTSTR)b->m_Desc,(LPCTSTR)b->m_Host);
	logLine=b->m_Pinged.Format(IDS_LOG_DATEFORMAT)+" "+logLine;
CBigBrotherDoc *pDoc = GetDocument();
	ASSERT(pDoc);
	pDoc->LogLine(logLine);
	return 0;
}

void CBigBrotherView::KillBrother(CBrother *b)
{
	ASSERT(b->m_Item);
CTreeCtrl& ctl = GetTreeCtrl();
HTREEITEM hItem = ctl.GetNextItem(b->m_Item,TVGN_CHILD);
	while(hItem){
	CBrother *bb = (CBrother*)ctl.GetItemData(hItem);
		ASSERT(bb);
		KillBrother(bb);
		hItem = ctl.GetNextItem(b->m_Item,TVGN_CHILD);
	}
	if(b->m_Daddy)
		KillOneBrother(b);
	// ??? Else - Cleanup?
}

void CBigBrotherView::KillOneBrother(CBrother *b)
{
	ASSERT(b);
	ASSERT(b->m_Item);
CTreeCtrl& ctl = GetTreeCtrl();
	ASSERT(!ctl.ItemHasChildren(b->m_Item));
	ctl.DeleteItem(b->m_Item);
	VERIFY(b->m_Doc=GetDocument());
	b->m_Item=NULL;
	b->Suicide();
}

void CBigBrotherView::SetupExpansion(CBrother *b)
{
	ASSERT(b->m_Item);
CTreeCtrl& ctl = GetTreeCtrl();
	if(b->flags&CBrother::flagsExpandedTree)
		ctl.Expand(b->m_Item,TVE_EXPAND);
HTREEITEM hItem = ctl.GetNextItem(b->m_Item,TVGN_CHILD);
	while(hItem){
	CBrother *bb = (CBrother*)ctl.GetItemData(hItem);
		ASSERT(bb);
		SetupExpansion(bb);
		hItem = ctl.GetNextItem(bb->m_Item,TVGN_NEXT);
	}
	if(b->flags&CBrother::flagsCurrentBrother)
		GotoBrother(b);
}

void CBigBrotherView::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
CBigBrotherDoc *pDoc = GetDocument();
	if(pDoc)
		pDoc->UpdateAllViews(this);
	*pResult = 0;
}

void CBigBrotherView::OnSetFocus(CWnd* pOldWnd) 
{
	CTreeView::OnSetFocus(pOldWnd);
	
CBigBrotherDoc *pDoc = GetDocument();
	if(!(pDoc && m_Pages))
		return;
	m_Pages->ShowWindow((pDoc->flags&CBigBrotherDoc::flagsShowProps)?SW_SHOW:SW_HIDE);
}
