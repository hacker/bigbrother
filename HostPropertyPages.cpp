// HostPropertyPages.cpp : implementation file
//

#include "stdafx.h"
#include "BigBrother.h"
#include "HostPropertyPages.h"
#include "GeneralPage.h"
#include "SettingsPage.h"
#include "ActionPage.h"
#include "BigBrotherDoc.h"
#include "BigBrotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHostPropertyPages

IMPLEMENT_DYNAMIC(CHostPropertyPages, CPropertySheet)

CHostPropertyPages::CHostPropertyPages(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage), m_Brother(NULL)
{
	CreatePages();
}

CHostPropertyPages::CHostPropertyPages(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage), m_Brother(NULL)
{
	CreatePages();
}

CHostPropertyPages::~CHostPropertyPages()
{
	delete m_Action;
	delete m_Settings;
	delete m_General;
}


BEGIN_MESSAGE_MAP(CHostPropertyPages, CPropertySheet)
	//{{AFX_MSG_MAP(CHostPropertyPages)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDOK, OnOK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHostPropertyPages message handlers

void CHostPropertyPages::CreatePages()
{
	m_General = new CGeneralPage();
	m_Settings = new CSettingsPage();
	m_Action = new CActionPage();
	m_General->m_dad=this;
	m_Settings->m_dad=this;
	m_Action->m_dad=this;
	AddPage(m_General);
	AddPage(m_Settings);
	AddPage(m_Action);
	m_InitialPosition.x=AfxGetApp()->GetProfileInt("PropertiesPosition","left",-1);
	m_InitialPosition.y=AfxGetApp()->GetProfileInt("PropertiesPosition","top",-1);	
}

void CHostPropertyPages::SetBrother(CBrother* b)
{
	if(m_Brother)
		UpdateBrother();
	m_Brother=b;
	m_General->UpdatePage();
	m_Settings->UpdatePage();
	m_Action->UpdatePage();
}

void CHostPropertyPages::UpdateBrother()
{
	if(!m_Brother)
		return;
	m_General->UpdateBrother();
	m_Settings->UpdateBrother();
	m_Action->UpdateBrother();
	ASSERT(m_Daddy);
CDocument *pDoc = m_Daddy->GetDocument();
	if(pDoc);
		pDoc->UpdateAllViews(NULL);
	//PostMessage(WM_UPDATETREEBROTHER,0,(LPARAM)m_Brother);
}

int CHostPropertyPages::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPropertySheet::OnCreate(lpCreateStruct) == -1)
		return -1;
	ModifyStyle(m_Daddy->IsWindowVisible()?0:WS_VISIBLE,WS_POPUP||WS_CLIPSIBLINGS|WS_BORDER|WS_DLGFRAME);
	ModifyStyleEx(0,WS_EX_TOOLWINDOW|WS_EX_WINDOWEDGE);
	return 0;
}

void CHostPropertyPages::OnDestroy() 
{
	CPropertySheet::OnDestroy();
CRect rc;
	GetWindowRect(rc);
	AfxGetApp()->WriteProfileInt("PropertiesPosition","left",rc.left);
	AfxGetApp()->WriteProfileInt("PropertiesPosition","top",rc.top);	
}

BOOL CHostPropertyPages::OnInitDialog() 
{
BOOL rv = CPropertySheet::OnInitDialog();
	VERIFY(m_OK.SubclassWindow(GetDlgItem(IDOK)->m_hWnd));
	m_OK.EnableWindow(TRUE);
	return rv;
}

void CHostPropertyPages::OnOK()
{
	UpdateBrother();
	AfxGetApp()->GetMainWnd()->SetFocus();
}
