// Preferences.cpp : implementation file
//

#include "stdafx.h"
#include "BigBrother.h"
#include "Preferences.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreferences dialog


CPreferences::CPreferences(CWnd* pParent /*=NULL*/)
	: CDialog(CPreferences::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreferences)
	m_AutosaveMinutes = 0;
	m_LogFile = _T("");
	m_MaxThreads = 0;
	m_PingSize = 0;
	m_SaveOnShutdown = FALSE;
	m_LogMins = 0;
	m_bStoreLastActivity = FALSE;
	//}}AFX_DATA_INIT
}


void CPreferences::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreferences)
	DDX_Control(pDX, IDC_LOGMINSPIN, m_LogMinSpinCtl);
	DDX_Control(pDX, IDC_LOGFILE, m_LogFileCtl);
	DDX_Control(pDX, IDC_THREADSPIN, m_ThreadsSpinCtl);
	DDX_Control(pDX, IDC_DATASIZESPIN, m_DatasizeSpinCtl);
	DDX_Control(pDX, IDC_BROWSE, m_BrowseCtl);
	DDX_Control(pDX, IDC_AUTOSPIN, m_AutosaveSpinCtl);
	DDX_Text(pDX, IDC_AUTOSAVEMINS, m_AutosaveMinutes);
	DDV_MinMaxUInt(pDX, m_AutosaveMinutes, 0, 300);
	DDX_Text(pDX, IDC_LOGFILE, m_LogFile);
	DDX_Text(pDX, IDC_MAXTHREADS, m_MaxThreads);
	DDV_MinMaxUInt(pDX, m_MaxThreads, 1, 50);
	DDX_Text(pDX, IDC_PINGSIZE, m_PingSize);
	DDV_MinMaxUInt(pDX, m_PingSize, 0, 32768);
	DDX_Check(pDX, IDC_SAVEONSHUTDOWN, m_SaveOnShutdown);
	DDX_Text(pDX, IDC_LOGMINS, m_LogMins);
	DDV_MinMaxUInt(pDX, m_LogMins, 1, 1440);
	DDX_Check(pDX, IDC_STOREACTIVITY, m_bStoreLastActivity);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreferences, CDialog)
	//{{AFX_MSG_MAP(CPreferences)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreferences message handlers

BOOL CPreferences::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_BrowseCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_BROWSESOUND));
	m_AutosaveSpinCtl.SetRange(0,300);
	m_DatasizeSpinCtl.SetRange(1,32767);
	m_ThreadsSpinCtl.SetRange(1,50);
	m_LogMinSpinCtl.SetRange(1,1440);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreferences::OnBrowse() 
{
CString filter;
	filter.LoadString(IDS_LOGFILTER);
CString title;
	title.LoadString(IDS_LOGFILE_SELECT);
CFileDialog cfd(FALSE,NULL,m_LogFile,OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY|OFN_NOTESTFILECREATE,filter,this);
	cfd.m_ofn.lpstrTitle=title;
	if(cfd.DoModal()==IDOK){
		m_LogFile=cfd.GetPathName();
		m_LogFileCtl.SetWindowText(cfd.GetPathName());
	}
}
