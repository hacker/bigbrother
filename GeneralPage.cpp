// GeneralPage.cpp : implementation file
//

#include "stdafx.h"
#include "BigBrother.h"
#include "GeneralPage.h"
#include "HostPropertyPages.h"
#include "BigBrotherDoc.h"
#include "BigBrotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralPage property page

IMPLEMENT_DYNCREATE(CGeneralPage, CPropertyPage)

CGeneralPage::CGeneralPage() : CPropertyPage(CGeneralPage::IDD)
{
	//{{AFX_DATA_INIT(CGeneralPage)
	m_Desc = _T("");
	m_Host = _T("");
	m_LogActivity = FALSE;
	//}}AFX_DATA_INIT
}

CGeneralPage::~CGeneralPage()
{
}

void CGeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralPage)
	DDX_Control(pDX, IDC_LOG_ACTIVITY, m_LogActivityCtl);
	DDX_Control(pDX, IDC_HOST, m_HostCtl);
	DDX_Control(pDX, IDC_DESC, m_DescCtl);
	DDX_Text(pDX, IDC_DESC, m_Desc);
	DDX_Text(pDX, IDC_HOST, m_Host);
	DDX_Check(pDX, IDC_LOG_ACTIVITY, m_LogActivity);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGeneralPage)
	ON_EN_CHANGE(IDC_HOST, OnChangeHost)
	ON_BN_CLICKED(IDC_LOG_ACTIVITY, OnLogActivity)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralPage message handlers

void CGeneralPage::OnChangeHost() 
{
CString h,d;
	m_HostCtl.GetWindowText(h);
	m_DescCtl.GetWindowText(d);
	if(d==m_Host){
		m_Desc=h;
		m_Host=h;
		m_DescCtl.SetWindowText(m_Desc);
	}
}

void CGeneralPage::OnLogActivity() 
{
	ASSERT(m_dad->m_Brother);
	if(!m_dad->m_Brother->m_Daddy){
	int tmp = m_LogActivityCtl.GetCheck();
		if(tmp==2){
			if(m_LogActivity)
				tmp=0;
			else
				tmp=1;
		}
		m_LogActivity=tmp;
	}else
		m_LogActivity=m_LogActivityCtl.GetCheck();
	m_LogActivityCtl.SetCheck(m_LogActivity);
	SetupControls();
}

void CGeneralPage::UpdatePage()
{
	if(!m_dad->m_Brother)
		return;
	m_Host=m_dad->m_Brother->m_Host;
	m_Desc=m_dad->m_Brother->m_Desc;
	m_LogActivity=(m_dad->m_Brother->flags&CBrother::flagsOverrideLogging)?(m_dad->m_Brother->m_bLog?1:0):2;
	if(::IsWindow(m_hWnd)){
		UpdateData(FALSE);
		SetupControls();
	}
}

BOOL CGeneralPage::OnSetActive() 
{
	UpdatePage();
	
	return CPropertyPage::OnSetActive();
}

void CGeneralPage::UpdateBrother()
{
	if(!m_dad->m_Brother){
		TRACE0("No brother on update\n");
		return;
	}
	if(::IsWindow(m_hWnd))
		UpdateData();
CBrother toCompare;
	toCompare = *m_dad->m_Brother;
	m_dad->m_Brother->m_Host=m_Host;
	m_dad->m_Brother->m_Desc=m_Desc;
	switch(m_LogActivity){
	case	0:
		m_dad->m_Brother->m_bLog=FALSE;
		m_dad->m_Brother->flags|=CBrother::flagsOverrideLogging;
		break;
	case	1:
		m_dad->m_Brother->m_bLog=TRUE;
		m_dad->m_Brother->flags|=CBrother::flagsOverrideLogging;
		break;
	default:
		m_dad->m_Brother->flags&=~CBrother::flagsOverrideLogging;
		break;
	}
	m_dad->m_Brother->ParentalAdjust();
	if(toCompare!=(*m_dad->m_Brother)){
	CDocument *pDoc = m_dad->m_Daddy->GetDocument();
		ASSERT(pDoc);
		pDoc->SetModifiedFlag();
	}
	if(::IsWindow(m_hWnd)){
		UpdateData(FALSE);
		SetupControls();
	}
	m_dad->m_Daddy->UpdateBrother(m_dad->m_Brother);
}

void CGeneralPage::SetupControls()
{
CString tmp;
	switch(m_LogActivity){
	case 0:
		tmp.LoadString(IDS_LOG_DONTLOG);
		break;
	case 1:
		tmp.LoadString(IDS_LOG_DOLOG);
		break;
	default:
		tmp.LoadString(IDS_LOG_ASKBIGBROTHER);
		break;
	}
	m_LogActivityCtl.SetWindowText(tmp);
}

BOOL CGeneralPage::OnKillActive() 
{
	UpdateBrother();
	return CPropertyPage::OnKillActive();
}
