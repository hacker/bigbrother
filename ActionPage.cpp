// ActionPage.cpp : implementation file
//

#include "stdafx.h"
#include "BigBrother.h"
#include "ActionPage.h"
#include "HostPropertyPages.h"
#include "BigBrotherDoc.h"
#include "BigBrotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CActionPage property page

IMPLEMENT_DYNCREATE(CActionPage, CPropertyPage)

CActionPage::CActionPage() : CPropertyPage(CActionPage::IDD)
{
	//{{AFX_DATA_INIT(CActionPage)
	m_bCustomDn = FALSE;
	m_bCustomUp = FALSE;
	m_OverrideAction = FALSE;
	m_bPlayASoundDn = FALSE;
	m_bPlayASoundUp = FALSE;
	m_CustomDn = _T("");
	m_CustomUp = _T("");
	m_SoundDn = _T("");
	m_SoundUp = _T("");
	//}}AFX_DATA_INIT
	m_PreplayIcon = AfxGetApp()->LoadIcon(IDI_PREPLAY);
	m_BrowseIcon = AfxGetApp()->LoadIcon(IDI_BROWSESOUND);
}

CActionPage::~CActionPage()
{
}

void CActionPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CActionPage)
	DDX_Control(pDX, IDC_BROWSE_SOUND_UP, m_BrowseUpCtl);
	DDX_Control(pDX, IDC_BROWSE_SOUND_DOWN, m_BrowseDnCtl);
	DDX_Control(pDX, IDC_PREVIEW_SOUND_UP, m_SoundPreviewUp);
	DDX_Control(pDX, IDC_PREVIEW_SOUND_DOWN, m_SoundPreviewDn);
	DDX_Control(pDX, IDC_SOUND_UP, m_SoundUpCtl);
	DDX_Control(pDX, IDC_SOUND_DOWN, m_SoundDnCtl);
	DDX_Control(pDX, IDC_PROGRAM_UP, m_CustomUpCtl);
	DDX_Control(pDX, IDC_PROGRAM_DOWN, m_CustomDnCtl);
	DDX_Control(pDX, IDC_PLAYASOUND_UP, m_bPlayASoundUpCtl);
	DDX_Control(pDX, IDC_PLAYASOUND_DOWN, m_bPlayASoundDnCtl);
	DDX_Control(pDX, IDC_OVERRIDE_ACTION, m_OverrideActionCtl);
	DDX_Control(pDX, IDC_CUSTOM_UP, m_bCustomUpCtl);
	DDX_Control(pDX, IDC_CUSTOM_DOWN, m_bCustomDnCtl);
	DDX_Check(pDX, IDC_CUSTOM_DOWN, m_bCustomDn);
	DDX_Check(pDX, IDC_CUSTOM_UP, m_bCustomUp);
	DDX_Check(pDX, IDC_OVERRIDE_ACTION, m_OverrideAction);
	DDX_Check(pDX, IDC_PLAYASOUND_DOWN, m_bPlayASoundDn);
	DDX_Check(pDX, IDC_PLAYASOUND_UP, m_bPlayASoundUp);
	DDX_Text(pDX, IDC_PROGRAM_DOWN, m_CustomDn);
	DDX_Text(pDX, IDC_PROGRAM_UP, m_CustomUp);
	DDX_CBString(pDX, IDC_SOUND_DOWN, m_SoundDn);
	DDX_CBString(pDX, IDC_SOUND_UP, m_SoundUp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CActionPage, CPropertyPage)
	//{{AFX_MSG_MAP(CActionPage)
	ON_BN_CLICKED(IDC_CUSTOM_DOWN, OnCustomDown)
	ON_BN_CLICKED(IDC_CUSTOM_UP, OnCustomUp)
	ON_BN_CLICKED(IDC_OVERRIDE_ACTION, OnOverrideAction)
	ON_BN_CLICKED(IDC_PLAYASOUND_DOWN, OnPlayasoundDown)
	ON_BN_CLICKED(IDC_PLAYASOUND_UP, OnPlayasoundUp)
	ON_BN_CLICKED(IDC_PREVIEW_SOUND_UP, OnPreviewSoundUp)
	ON_BN_CLICKED(IDC_PREVIEW_SOUND_DOWN, OnPreviewSoundDown)
	ON_BN_CLICKED(IDC_BROWSE_SOUND_DOWN, OnBrowseSoundDown)
	ON_BN_CLICKED(IDC_BROWSE_SOUND_UP, OnBrowseSoundUp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CActionPage message handlers

void CActionPage::SetupControls()
{
	m_bPlayASoundUpCtl.EnableWindow(m_OverrideAction);
	m_bPlayASoundDnCtl.EnableWindow(m_OverrideAction);
	m_bCustomUpCtl.EnableWindow(m_OverrideAction);
	m_bCustomDnCtl.EnableWindow(m_OverrideAction);
	m_SoundUpCtl.EnableWindow(m_bPlayASoundUp&&m_OverrideAction);
	m_SoundDnCtl.EnableWindow(m_bPlayASoundDn&&m_OverrideAction);
	m_SoundPreviewUp.EnableWindow(m_bPlayASoundUp);
	m_SoundPreviewDn.EnableWindow(m_bPlayASoundDn);
	m_BrowseUpCtl.EnableWindow(m_bPlayASoundUp&&m_OverrideAction);
	m_BrowseDnCtl.EnableWindow(m_bPlayASoundDn&&m_OverrideAction);
	m_CustomUpCtl.EnableWindow(m_bCustomUp&&m_OverrideAction);
	m_CustomDnCtl.EnableWindow(m_bCustomDn&&m_OverrideAction);
}

void CActionPage::UpdatePage()
{
	if(!m_dad->m_Brother)
		return;
	if(::IsWindow(m_hWnd)){
		m_SoundPreviewUp.SetIcon(m_PreplayIcon);
		m_SoundPreviewDn.SetIcon(m_PreplayIcon);
		m_BrowseUpCtl.SetIcon(m_BrowseIcon);
		m_BrowseDnCtl.SetIcon(m_BrowseIcon);
		if(m_dad->m_Brother->m_Daddy)
			m_OverrideActionCtl.EnableWindow(TRUE);
		else
			m_OverrideActionCtl.EnableWindow(FALSE);
	}
	if(m_dad->m_Brother->flags&CBrother::flagsOverrideActions)
		m_OverrideAction=TRUE;
	else
		m_OverrideAction=FALSE;
	if(m_dad->m_Brother->m_Up.flags&CAction::flagsPlayASound)
		m_bPlayASoundUp=TRUE;
	else
		m_bPlayASoundUp=FALSE;
	if(m_dad->m_Brother->m_Up.flags&CAction::flagsRunCustom)
		m_bCustomUp=TRUE;
	else
		m_bCustomUp=FALSE;
	if(m_dad->m_Brother->m_Down.flags&CAction::flagsPlayASound)
		m_bPlayASoundDn=TRUE;
	else
		m_bPlayASoundDn=FALSE;
	if(m_dad->m_Brother->m_Down.flags&CAction::flagsRunCustom)
		m_bCustomDn=TRUE;
	else
		m_bCustomDn=FALSE;
	m_SoundUp=m_dad->m_Brother->m_Up.m_Sound;
	m_CustomUp=m_dad->m_Brother->m_Up.m_Custom;
	m_SoundDn=m_dad->m_Brother->m_Down.m_Sound;
	m_CustomDn=m_dad->m_Brother->m_Down.m_Custom;
	if(::IsWindow(m_hWnd)){
		UpdateData(FALSE);
		SetupControls();
	}
}

BOOL CActionPage::OnSetActive() 
{
	UpdatePage();
	return CPropertyPage::OnSetActive();
}

void CActionPage::UpdateBrother()
{
	if(!m_dad->m_Brother){
		TRACE0("No brother on update\n");
		return;
	}
	if(::IsWindow(m_hWnd))
		UpdateData();
CBrother toCompare;
	toCompare = *m_dad->m_Brother;
	if(m_OverrideAction)
		m_dad->m_Brother->flags|=CBrother::flagsOverrideActions;
	else
		m_dad->m_Brother->flags&=~CBrother::flagsOverrideActions;
	if(m_bPlayASoundUp)
		m_dad->m_Brother->m_Up.flags|=CAction::flagsPlayASound;
	else
		m_dad->m_Brother->m_Up.flags&=~CAction::flagsPlayASound;
	m_dad->m_Brother->m_Up.m_Sound=m_SoundUp;
	if(m_bCustomUp)
		m_dad->m_Brother->m_Up.flags|=CAction::flagsRunCustom;
	else
		m_dad->m_Brother->m_Up.flags&=~CAction::flagsRunCustom;
	m_dad->m_Brother->m_Up.m_Custom=m_CustomUp;
	if(m_bPlayASoundDn)
		m_dad->m_Brother->m_Down.flags|=CAction::flagsPlayASound;
	else
		m_dad->m_Brother->m_Down.flags&=~CAction::flagsPlayASound;
	m_dad->m_Brother->m_Down.m_Sound=m_SoundDn;
	if(m_bCustomDn)
		m_dad->m_Brother->m_Down.flags|=CAction::flagsRunCustom;
	else
		m_dad->m_Brother->m_Down.flags&=~CAction::flagsRunCustom;
	m_dad->m_Brother->m_Down.m_Custom=m_CustomDn;
	m_dad->m_Brother->ParentalAdjust();
	if(toCompare!=(*m_dad->m_Brother)){
		ASSERT(m_dad->m_Daddy);
		CDocument *pDoc = m_dad->m_Daddy->GetDocument();
		ASSERT(pDoc);
		pDoc->SetModifiedFlag();
	}
	if(::IsWindow(m_hWnd)){
		UpdateData(FALSE);
		SetupControls();
	}
}

BOOL CActionPage::OnKillActive() 
{
	UpdateBrother();
	return CPropertyPage::OnKillActive();
}

void CActionPage::OnCustomDown() 
{
	UpdateBrother();
	if(m_bCustomDn)
		m_CustomDnCtl.SetFocus();
}

void CActionPage::OnCustomUp() 
{
	UpdateBrother();
	if(m_bCustomUp)
		m_CustomUpCtl.SetFocus();
}

void CActionPage::OnOverrideAction() 
{
	UpdateBrother();
}

void CActionPage::OnPlayasoundDown() 
{
	UpdateBrother();
	if(m_bPlayASoundDn)
		m_SoundDnCtl.SetFocus();
}

void CActionPage::OnPlayasoundUp() 
{
	UpdateBrother();
	if(m_bPlayASoundUp)
		m_SoundUpCtl.SetFocus();
}

void CActionPage::OnPreviewSoundUp() 
{
	ASSERT(m_bPlayASoundUp);
	UpdateBrother();
	CAction::PlayASound(m_SoundUp);
}

void CActionPage::OnPreviewSoundDown() 
{
	ASSERT(m_bPlayASoundDn);
	UpdateBrother();
	CAction::PlayASound(m_SoundDn);
}

void CActionPage::OnBrowseSoundDown() 
{
	BrowseCtl(m_SoundDnCtl);
}

void CActionPage::OnBrowseSoundUp() 
{
	BrowseCtl(m_SoundUpCtl);
}

void CActionPage::BrowseCtl(CComboBox& ctl)
{
CString filter;
	filter.LoadString(IDS_WAVFILTER);
CString title;
	title.LoadString(IDS_SOUND_SELECT);
CFileDialog cfd(TRUE,NULL,NULL,OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,filter,this);
	cfd.m_ofn.lpstrTitle=title;
	if(cfd.DoModal()==IDOK){
		ctl.SetWindowText(cfd.GetPathName());
		UpdateBrother();
	}
}
