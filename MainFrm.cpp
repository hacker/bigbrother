// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "BigBrother.h"

#include "MainFrm.h"
#include "BigBrotherView.h"
#include "ActivityView.h"
#include "BigBrotherDoc.h"
#include "HostPropertyPages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(ID_VIEW_MAINWINDOW, OnUpdateViewMainwindow)
	ON_COMMAND(ID_VIEW_MAINWINDOW, OnViewMainwindow)
	ON_WM_WINDOWPOSCHANGING()
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PINGBAR, OnUpdateIndicatorPingbar)
	ON_WM_CLOSE()
	ON_MESSAGE(WM_TRAYICONMESSAGE, OnNotifyIcon)
	ON_WM_QUERYENDSESSION()
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_INDICATOR_PINGBAR,
	ID_SEPARATOR           // status line indicator
/*	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL*/
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bExiting=FALSE;
	m_bShuttingDown=FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this,WS_CHILD | WS_VISIBLE | CBRS_BOTTOM|CBRS_SIZE_DYNAMIC) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetPaneStyle(1,m_wndStatusBar.GetPaneStyle(1)|SBPS_STRETCH);
	VERIFY(m_PingBar.Create(WS_CHILD|WS_VISIBLE|ACS_TRANSPARENT,CRect(0,0,0,0),&m_wndStatusBar,ID_INDICATOR_PINGBAR));
	m_PingBar.Open(IDR_PINGBAR);
CRect rc;
	m_PingBar.GetWindowRect(rc);
int nHorz, nVert, nSpacing;
	m_wndStatusBar.GetStatusBarCtrl().GetBorders(nHorz,nVert,nSpacing);
	m_wndStatusBar.GetStatusBarCtrl().SetMinHeight(rc.Height()+nVert*2);
	m_wndStatusBar.SetTheMinHeight(rc.Height()+nVert*2);
	m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_INDICATOR_PINGBAR),ID_INDICATOR_PINGBAR,SBPS_NORMAL,rc.Width());
	m_PingBar.SetWindowPos(NULL,nHorz+nSpacing+1,nVert+1,0,0,SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

NOTIFYICONDATA nid;
	memset(&nid,0,sizeof(nid));
	nid.cbSize=sizeof(nid);
	nid.hWnd=m_hWnd;
	nid.uID=IDC_TRAYICON;
	nid.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
	nid.uCallbackMessage=WM_TRAYICONMESSAGE;
	nid.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// *** Load from resource
	strcpy(nid.szTip,"Big Brother");
	VERIFY(Shell_NotifyIcon(NIM_ADD,&nid));
	return 0;
}

BOOL CMainFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	if(!m_wndSplitter.CreateStatic(this,2,1)){
		TRACE0("Failed to create static splitter\n");
		return FALSE;
	}
CRect rc;
	GetClientRect(rc);
int cySize = AfxGetApp()->GetProfileInt("SplitterPosition","TreeSize",-1);
	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CBigBrotherView),CSize(0,(cySize<0)?(rc.Height()/2):cySize),pContext)){
		TRACE0("Failed to create Tree View\n");
		return FALSE;
	}
	cySize = AfxGetApp()->GetProfileInt("SplitterPosition","ActivitySize",-1);
	if(!m_wndSplitter.CreateView(1,0,RUNTIME_CLASS(CActivityView),CSize(0,(cySize<0)?(rc.Height()/2):cySize),pContext)){
		TRACE0("Failed to create Activity View\n");
		return FALSE;
	}
	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
CRect rc;
CWinApp *app = AfxGetApp();
	rc.left=app->GetProfileInt("FramePosition","left",-1);
	rc.top=app->GetProfileInt("FramePosition","top",-1);
	rc.right=app->GetProfileInt("FramePosition","right",-1);
	rc.bottom=app->GetProfileInt("FramePosition","bottom",-1);
	if(rc.left>=0 && rc.top>=0 && rc.right>=0 && rc.bottom>=0){
		cs.x=rc.left, cs.y=rc.top;
		cs.cx=rc.Width(), cs.cy=rc.Height();
	}
int	tmp = app->GetProfileInt("FramePosition","shown",-1);
	if(!tmp){
		cs.style&=~WS_VISIBLE;
		m_bShown=FALSE;
	}else
		m_bShown=TRUE;
	cs.style&=~WS_MINIMIZEBOX|WS_MAXIMIZEBOX;
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	
	m_bExiting=TRUE;

	// Save window size and position
CRect rc;
	GetWindowRect(rc);
CWinApp *app = AfxGetApp();
	app->WriteProfileInt("FramePosition","left",rc.left);
	app->WriteProfileInt("FramePosition","top",rc.top);
	app->WriteProfileInt("FramePosition","right",rc.right);
	app->WriteProfileInt("FramePosition","bottom",rc.bottom);
int cyCur,cyMin;
	m_wndSplitter.GetRowInfo(0,cyCur,cyMin);
	app->WriteProfileInt("SplitterPosition","TreeSize",cyCur);
	m_wndSplitter.GetRowInfo(1,cyCur,cyMin);
	app->WriteProfileInt("SplitterPosition","ActivitySize",cyCur);
	app->WriteProfileInt("FramePosition","shown",m_bShown);

NOTIFYICONDATA nid;
	memset(&nid,0,sizeof(nid));
	nid.cbSize=sizeof(nid);
	nid.hWnd=m_hWnd;
	nid.uID=IDC_TRAYICON;
	nid.uFlags=0;
	VERIFY(Shell_NotifyIcon(NIM_DELETE,&nid));
}

LRESULT CMainFrame::OnNotifyIcon(WPARAM wP,LPARAM lP)
{
	ASSERT(wP==IDC_TRAYICON);
	switch(lP){
	case WM_LBUTTONDOWN:
		OnViewMainwindow();
		break;
	case WM_RBUTTONDOWN:
		{
		CMenu menu;
			VERIFY(menu.LoadMenu(IDM_POPUPS));
		CMenu *popUp = menu.GetSubMenu(0);
			ASSERT(popUp);
		CPoint pt;
			VERIFY(::GetCursorPos(&pt));
			popUp->TrackPopupMenu(TPM_RIGHTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,pt.x,pt.y,this,NULL);
		}
		break;
	default:
/*		{
		CString tmp;
			tmp.Format("NIMESSAGE: %08lX\n",lP);
			TRACE0(tmp);
		}*/
		break;
	}
	return 0;
}

void CMainFrame::FrameDisplayState(BOOL bShow)
{
	m_bShown=bShow;
	ShowWindow(bShow?SW_SHOW:SW_HIDE);
CBigBrotherDoc *doc = (CBigBrotherDoc*)GetActiveDocument();
	if(doc){
		ASSERT(doc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
		ASSERT(doc->m_BBView);
		ASSERT(doc->m_BBView->m_Pages);
		ASSERT(::IsWindow(doc->m_BBView->m_Pages->m_hWnd));
		doc->m_BBView->m_Pages->ShowWindow(bShow?SW_SHOW:SW_HIDE);
	}
	if(bShow){
		SetForegroundWindow();
		SetFocus();
	}
}

void CMainFrame::OnUpdateViewMainwindow(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(IsWindowVisible()?1:0);
}

void CMainFrame::OnViewMainwindow() 
{
	FrameDisplayState(!IsWindowVisible());
}

void CMainFrame::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos) 
{
	if(!m_bExiting){
		if(m_bShown){
			lpwndpos->flags&=~SWP_HIDEWINDOW;
			lpwndpos->flags|=SWP_SHOWWINDOW;
		}else{
			lpwndpos->flags&=~SWP_SHOWWINDOW;
			lpwndpos->flags|=SWP_HIDEWINDOW;
		}
	}
	CFrameWnd::OnWindowPosChanging(lpwndpos);
}

void CMainFrame::OnUpdateIndicatorPingbar(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TRUE);
}

void CMainFrame::OnClose() 
{
	m_bExiting=TRUE;
	CFrameWnd::OnClose();
}

BOOL CMainFrame::OnQueryEndSession() 
{
	m_bShuttingDown=TRUE;
	if (!CFrameWnd::OnQueryEndSession())
		return FALSE;
	::PostQuitMessage(0);
	return TRUE;
}
