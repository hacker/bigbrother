// SettingsPage.cpp : implementation file
//

#include "stdafx.h"
#include "BigBrother.h"
#include "SettingsPage.h"
#include "HostPropertyPages.h"
#include "BigBrotherDoc.h"
#include "BigBrotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingsPage property page

IMPLEMENT_DYNCREATE(CSettingsPage, CPropertyPage)

CSettingsPage::CSettingsPage() : CPropertyPage(CSettingsPage::IDD)
{
	//{{AFX_DATA_INIT(CSettingsPage)
	m_OverrideIntervals = FALSE;
	m_OverrideRetries = FALSE;
	m_OverrideTimeout = FALSE;
	m_IntervalBad = 0;
	m_IntervalGood = 0;
	m_TimeOut = 0;
	m_Retries = 0;
	//}}AFX_DATA_INIT
}

CSettingsPage::~CSettingsPage()
{
}

void CSettingsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingsPage)
	DDX_Control(pDX, IDC_RETRIES, m_RetriesCtl);
	DDX_Control(pDX, IDC_PINGTIMEOUT, m_TimeOutCtl);
	DDX_Control(pDX, IDC_PINGINTERVAL_GOOD, m_IntervalGoodCtl);
	DDX_Control(pDX, IDC_PINGINTERVAL_BAD, m_IntervalBadCtl);
	DDX_Control(pDX, IDC_OVERRIDE_TIMEOUT, m_OverrideTimeoutCtl);
	DDX_Control(pDX, IDC_OVERRIDE_RETRIES, m_OverrideRetriesCtl);
	DDX_Control(pDX, IDC_OVERRIDE_INTERVALS, m_OverrideIntervalsCtl);
	DDX_Check(pDX, IDC_OVERRIDE_INTERVALS, m_OverrideIntervals);
	DDX_Check(pDX, IDC_OVERRIDE_RETRIES, m_OverrideRetries);
	DDX_Check(pDX, IDC_OVERRIDE_TIMEOUT, m_OverrideTimeout);
	DDX_Text(pDX, IDC_PINGINTERVAL_BAD, m_IntervalBad);
	DDX_Text(pDX, IDC_PINGINTERVAL_GOOD, m_IntervalGood);
	DDX_Text(pDX, IDC_PINGTIMEOUT, m_TimeOut);
	DDX_Text(pDX, IDC_RETRIES, m_Retries);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSettingsPage)
	ON_BN_CLICKED(IDC_OVERRIDE_INTERVALS, OnOverrideIntervals)
	ON_BN_CLICKED(IDC_OVERRIDE_RETRIES, OnOverrideRetries)
	ON_BN_CLICKED(IDC_OVERRIDE_TIMEOUT, OnOverrideTimeout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingsPage message handlers

void CSettingsPage::SetupControls()
{
	m_IntervalBadCtl.EnableWindow(m_OverrideIntervals);
	m_IntervalGoodCtl.EnableWindow(m_OverrideIntervals);
	m_RetriesCtl.EnableWindow(m_OverrideRetries);
	m_TimeOutCtl.EnableWindow(m_OverrideTimeout);
}

void CSettingsPage::UpdatePage()
{
	if(!m_dad->m_Brother)
		return;
	if(::IsWindow(m_hWnd)){
		if(m_dad->m_Brother->m_Daddy){
			m_OverrideIntervalsCtl.EnableWindow(TRUE);
			m_OverrideRetriesCtl.EnableWindow(TRUE);
			m_OverrideTimeoutCtl.EnableWindow(TRUE);
		}else{
			m_OverrideIntervalsCtl.EnableWindow(FALSE);
			m_OverrideRetriesCtl.EnableWindow(FALSE);
			m_OverrideTimeoutCtl.EnableWindow(FALSE);
		}
	}
	if(m_dad->m_Brother->flags&CBrother::flagsOverrideIntervals)
		m_OverrideIntervals=TRUE;
	else
		m_OverrideIntervals=FALSE;
	if(m_dad->m_Brother->flags&CBrother::flagsOverrideTimeout)
		m_OverrideTimeout=TRUE;
	else
		m_OverrideTimeout=FALSE;
	if(m_dad->m_Brother->flags&CBrother::flagsOverrideRetries)
		m_OverrideRetries=TRUE;
	else
		m_OverrideRetries=FALSE;
	m_IntervalBad=m_dad->m_Brother->m_IntervalBad;
	m_IntervalGood=m_dad->m_Brother->m_IntervalGood;
	m_Retries=m_dad->m_Brother->m_Retries;
	m_TimeOut=m_dad->m_Brother->m_TimeOut;
	if(::IsWindow(m_hWnd)){
		UpdateData(FALSE);
		SetupControls();
	}
}

BOOL CSettingsPage::OnSetActive() 
{
	UpdatePage();
	return CPropertyPage::OnSetActive();
}

void CSettingsPage::OnOverrideIntervals() 
{
	UpdateBrother();
	if(m_OverrideIntervals)
		m_IntervalGoodCtl.SetFocus();
}

void CSettingsPage::OnOverrideRetries() 
{
	UpdateBrother();
	if(m_OverrideRetries)
		m_RetriesCtl.SetFocus();
}

void CSettingsPage::OnOverrideTimeout() 
{
	UpdateBrother();
	if(m_OverrideTimeout)
		m_TimeOutCtl.SetFocus();
}

void CSettingsPage::UpdateBrother()
{
	if(!m_dad->m_Brother){
		TRACE0("No brother on update\n");
		return;
	}
	if(::IsWindow(m_hWnd))
		UpdateData();
CBrother toCompare;
	toCompare = *m_dad->m_Brother;
	m_dad->m_Brother->m_IntervalBad=m_IntervalBad;
	m_dad->m_Brother->m_IntervalGood=m_IntervalGood;
	if(m_OverrideIntervals)
		m_dad->m_Brother->flags|=CBrother::flagsOverrideIntervals;
	else
		m_dad->m_Brother->flags&=~CBrother::flagsOverrideIntervals;
	m_dad->m_Brother->m_Retries=m_Retries;
	if(m_OverrideRetries)
		m_dad->m_Brother->flags|=CBrother::flagsOverrideRetries;
	else
		m_dad->m_Brother->flags&=~CBrother::flagsOverrideRetries;
	m_dad->m_Brother->m_TimeOut=m_TimeOut;
	if(m_OverrideTimeout)
		m_dad->m_Brother->flags|=CBrother::flagsOverrideTimeout;
	else
		m_dad->m_Brother->flags&=~CBrother::flagsOverrideTimeout;
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
}

BOOL CSettingsPage::OnKillActive() 
{
	UpdateBrother();
	return CPropertyPage::OnKillActive();
}
