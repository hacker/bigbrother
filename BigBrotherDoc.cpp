// BigBrotherDoc.cpp : implementation of the CBigBrotherDoc class
//

#include "stdafx.h"
#include "BigBrother.h"

#include "BigBrotherDoc.h"
#include "BigBrotherView.h"
#include "ActivityView.h"
#include "HostPropertyPages.h"
#include "MainFrm.h"
#include "Preferences.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherDoc

IMPLEMENT_SERIAL(CBigBrotherDoc, CDocument, VERSIONABLE_SCHEMA | 3 )
IMPLEMENT_SERIAL(CBrother, CObject, VERSIONABLE_SCHEMA | 2 )
IMPLEMENT_SERIAL(CAction, CObject, VERSIONABLE_SCHEMA | 1 )
IMPLEMENT_SERIAL(CLogEntry, CObject, VERSIONABLE_SCHEMA | 2 )

BEGIN_MESSAGE_MAP(CBigBrotherDoc, CDocument)
	//{{AFX_MSG_MAP(CBigBrotherDoc)
	ON_COMMAND(ID_BROTHERS_NEW, OnBrothersNew)
	ON_UPDATE_COMMAND_UI(ID_BROTHERS_ADDBROTHER, OnUpdateBrothersAddbrother)
	ON_COMMAND(ID_BROTHERS_ADDBROTHER, OnBrothersAddbrother)
	ON_UPDATE_COMMAND_UI(ID_BROTHERS_DELETE, OnUpdateBrothersDelete)
	ON_COMMAND(ID_BROTHERS_DELETE, OnBrothersDelete)
	ON_COMMAND(ID_FILE_PREFERENCES, OnFilePreferences)
	ON_UPDATE_COMMAND_UI(ID_FILE_PAUSE, OnUpdateFilePause)
	ON_COMMAND(ID_FILE_PAUSE, OnFilePause)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HOSTPROPERTIES, OnUpdateViewHostproperties)
	ON_COMMAND(ID_VIEW_HOSTPROPERTIES, OnViewHostproperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherDoc construction/destruction

CBigBrotherDoc::CBigBrotherDoc()
	: m_MaxLogTime(0,1,0,0), m_Threads(0), m_MaxThreads(10), m_PingSize(32), m_RootBrother(NULL),
	  m_bSaveOnShutdown(TRUE), m_AutoSave(0,0,30,0), m_bStoreLastActivity(FALSE)
{
	m_BBView = NULL;
	m_AView = NULL;
}

CBigBrotherDoc::~CBigBrotherDoc()
{
	CleanUp();
}

BOOL CBigBrotherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	CleanUp();
	m_RootBrother=new CBrother();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherDoc serialization

void CBigBrotherDoc::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	CDocument::Serialize(ar);

	ar.MapObject(this);
	ar.SerializeClass(RUNTIME_CLASS(CBigBrotherDoc));

	if (ar.IsStoring())
	{
		// Store to archive
		ar << m_PingSize;
		ar << m_MaxThreads;
		ar << m_MaxLogTime;
		ar << m_bSaveOnShutdown;
		ar << m_AutoSave;
		ar << m_LogFile;
		ar << m_bStoreLastActivity;
		ar << m_RootBrother;
		m_Brotherhood.Serialize(ar);
	}
	else
	{
	UINT	schema = ar.GetObjectSchema();
#ifndef	NDEBUG
		{
		CString tmp;
			tmp.Format("Doc-OSchema: %u\n",schema);
			TRACE0(tmp);
		}
#endif
		CleanUp();
		m_ThisMap.RemoveAll();
		// Read from archive
		ar >> m_PingSize;
		ar >> m_MaxThreads;
		ar >> m_MaxLogTime;
		if(schema>=2){
			ar >> m_bSaveOnShutdown;
			ar >> m_AutoSave;
		}
		ar >> m_LogFile;
		if(schema>=3)
			ar >> m_bStoreLastActivity;
		ar >> m_RootBrother;
		m_Brotherhood.Serialize(ar);
		// Read from archive
		m_ThisMap.RemoveAll();
		// Log loading
	CString logLine;
		logLine.Format(IDS_LOG_LOADFILE,(LPCTSTR)GetTitle());
		logLine=CTime::GetCurrentTime().Format(IDS_LOG_DATEFORMAT)+" "+logLine;
		LogLine(logLine);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherDoc diagnostics

#ifdef _DEBUG
void CBigBrotherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBigBrotherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBigBrotherDoc commands

CBrother::CBrother(CBrother *daddy)
{
	CleanUp();
	m_Daddy=daddy;
	ParentalAdjust(TRUE);
}

void CBrother::CleanUp()
{
	m_Item=NULL;
	flags=0;
	m_bLog=TRUE;
	m_Daddy=NULL;
	m_Desc.Empty();
	m_Down.CleanUp();
	m_Host.Empty();
	m_IntervalBad=30;
	m_IntervalGood=30;
	m_Retries=3;
	m_TimeOut=5000;
	m_Up.CleanUp();
	m_bPinged=FALSE;
	m_bPending=FALSE;
	m_bIsUp=TRUE;
	m_bPinging=FALSE;
	m_bUp=TRUE;
	m_bToKill=FALSE;
	m_Doc=NULL;
}

CAction::CAction()
{
	CleanUp();
}

void CAction::CleanUp()
{
	flags=0;
	m_Custom.Empty();
	m_Sound.Empty();
}

CAction& CAction::operator=(CAction& src)
{
	flags=src.flags;
	m_Custom=src.m_Custom;
	m_Sound=src.m_Sound;
	return *this;
}

void CBrother::ParentalAdjust(BOOL cleanUp)
{
	if(!m_Daddy){
		flags|=flagsOverrideIntervals|flagsOverrideTimeout|flagsOverrideRetries|flagsOverrideActions|flagsOverrideLogging;
		if(cleanUp){
			m_Desc.LoadString(IDS_ROOTNODENAME);
			m_IntervalBad=30, m_IntervalGood=30;
			m_TimeOut=5000;
			m_Retries=3;
			{
				m_Up.CleanUp();
				m_Down.CleanUp();
				m_Up.flags=m_Down.flags=CAction::flagsPlayASound;
				m_Up.m_Sound.LoadString(IDS_ACTION_HOST_UP);
				m_Down.m_Sound.LoadString(IDS_ACTION_HOST_DOWN);
			}
			m_bLog=TRUE;
		}
	}else{
		if(!(flags&flagsOverrideIntervals)){
		CBrother *parent = m_Daddy;
			while(!(parent->flags&flagsOverrideIntervals)){
				ASSERT(parent->m_Daddy);
				parent=parent->m_Daddy;
			}
			m_IntervalBad=parent->m_IntervalBad;
			m_IntervalGood=parent->m_IntervalGood;
		}
		if(!(flags&flagsOverrideTimeout)){
		CBrother *parent = m_Daddy;
			while(!(parent->flags&flagsOverrideTimeout)){
				ASSERT(parent->m_Daddy);
				parent=parent->m_Daddy;
			}
			m_TimeOut=parent->m_TimeOut;
		}
		if(!(flags&flagsOverrideRetries)){
		CBrother *parent = m_Daddy;
			while(!(parent->flags&flagsOverrideRetries)){
				ASSERT(parent->m_Daddy);
				parent=parent->m_Daddy;
			}
			m_Retries=parent->m_Retries;
		}
		if(!(flags&flagsOverrideActions)){
		CBrother *parent = m_Daddy;
			while(!(parent->flags&flagsOverrideActions)){
				ASSERT(parent->m_Daddy);
				parent=parent->m_Daddy;
			}
			m_Up=parent->m_Up;
			m_Down=parent->m_Down;
		}
		if(!(flags&flagsOverrideLogging)){
		CBrother *parent = m_Daddy;
			while(!(parent->flags&flagsOverrideLogging)){
				ASSERT(parent->m_Daddy);
				parent=parent->m_Daddy;
			}
			m_bLog=parent->m_bLog;
		}
	}
}

void CBigBrotherDoc::OnChangedViewList() 
{
	m_BBView=NULL;
	m_AView=NULL;
POSITION p = GetFirstViewPosition();
	while(p){
	CView* v = GetNextView(p);
		if(v->IsKindOf(RUNTIME_CLASS(CBigBrotherView))){
			ASSERT(!m_BBView);
			m_BBView=(CBigBrotherView*)v;
		}else if(v->IsKindOf(RUNTIME_CLASS(CActivityView))){
			ASSERT(!m_AView);
			m_AView=(CActivityView*)v;
		}
	}
	
	CDocument::OnChangedViewList();
}

void CBigBrotherDoc::OnBrothersNew() 
{
	ASSERT(m_BBView);
CBrother *bro = m_BBView->GetCurrentBrother();
	ASSERT(bro);
CBrother *lb = new CBrother(bro);
	m_Brotherhood.AddTail(lb);
	SetModifiedFlag();
	m_BBView->AddBrother(lb);
	m_BBView->GotoBrother(lb);
}

void CBigBrotherDoc::CheckPendingQueue()
{
	if(flags&flagsSuspended)
		return;
CTime currentTime = CTime::GetCurrentTime();
CTime nearestCheck;
BOOL nearested = CheckPendingBrother(m_RootBrother,currentTime,nearestCheck,FALSE);
POSITION p = m_Brotherhood.GetHeadPosition();
	while(p){
	CBrother *b = (CBrother*)m_Brotherhood.GetNext(p);
		ASSERT(b);
		nearested|=CheckPendingBrother(b,currentTime,nearestCheck,nearested);
	}
	if(m_AutoSave.GetTotalMinutes()){
	CTime nc = m_AutoSaved+m_AutoSave;
		if(nc<=currentTime){
			if(IsModified())
				DoFileSave();
			m_AutoSaved=currentTime;
			while(nc<=currentTime)
				nc=nc+m_AutoSave;
		}
		if((!nearested) || nc<nearestCheck){
			nearestCheck=nc;
			nearested=TRUE;
		}
	}
	if(!nearested)
		return;
	currentTime = CTime::GetCurrentTime();
CTimeSpan nextto = nearestCheck-currentTime;
UINT	timer = 60000;
	if(nextto.GetTotalSeconds()<60)
		timer=nextto.GetTotalSeconds()*1000;
	if(m_BBView)	// In case we're destroying..
		m_BBView->SetTimer(TM_CHECK,timer,NULL);
}

BOOL CBigBrotherDoc::CheckPendingBrother(CBrother* b,CTime& currentTime,CTime& nearestCheck,BOOL nearested)
{
	if(!b)
		return FALSE;
	if(b->m_Host.IsEmpty() || b->m_bPinging){
		b->m_bPending=FALSE;
		return FALSE;
	}
	if(b->m_bPending){
		TryBrother(b);
		return FALSE;
	}
CTime nextCheck = b->m_Pinged+CTimeSpan(b->m_bIsUp?b->m_IntervalGood:b->m_IntervalBad);
	if(nextCheck<=currentTime){
		TryBrother(b);
		return FALSE;
	}
	if((!nearested) || nextCheck<nearestCheck){
		nearestCheck=nextCheck;
		return TRUE;
	}
	return FALSE;
}

void CBigBrotherDoc::TryBrother(CBrother *b)
{
	ASSERT(!b->m_Host.IsEmpty());
	if(!(m_Threads<m_MaxThreads)){
		b->m_bPending=TRUE;
		return;
	}
	if(!m_BBView)
		return;	// In case we're dying
	m_BBView->SendMessage(WM_ACTIVITYCOUNT,1,0);
	b->m_Doc=this;
	b->m_bPinging=TRUE;
	VERIFY(AfxBeginThread(CBrother::DoCheck,(LPVOID)b));
}

UINT CBrother::DoCheck(LPVOID pParam)
{
CBrother *b = (CBrother*)pParam;
	ASSERT(b);
	return b->Check();
}

UINT CBrother::Check()
{
CBigBrotherDoc *m_Doc = (CBigBrotherDoc*)CBrother::m_Doc;

	if(!m_bToKill){
		ASSERT(m_Doc);
		ASSERT(m_Doc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
		ASSERT(m_Doc->m_BBView);
		m_Doc->m_BBView->PostMessage(WM_UPDATETREEBROTHER,0,(LPARAM)this);
	}

CICMP *pICMP = NULL;
UINT dataSize = m_bToKill?32:m_Doc->m_PingSize;
in_addr ip;
	ip.s_addr = inet_addr(m_Host);
CLogEntry le;
	if(ip.s_addr==INADDR_NONE){
	hostent *he = gethostbyname(m_Host);
		if(!he){
			le.m_Status.LoadString(IDS_PS_FAILEDTORESOLVE);
			goto goBye;
		}
		memmove(&ip.s_addr,he->h_addr,sizeof(ip.s_addr));
	}
	pICMP = CICMP::CreateICMP();
	if(!(pICMP && pICMP->Initialize())) {
		le.m_Status.LoadString(IDS_PS_UNABLETOICMP);
		goto goBye;
	}
	INT status;
	LONG rtt;
	rtt=pICMP->Ping(ip,dataSize,m_TimeOut,&status);
	switch(status){
	case CICMP::ipSuccess:
		le.m_bReached=TRUE;
		le.m_RTT=rtt;
		le.m_Status.Empty();
		break;
	case CICMP::ipBuffTooSmall:
		le.m_Status.LoadString(IDS_PS_INTERNALERROR);
		break;
	case CICMP::ipDestNetUnreachable:
		le.m_Status.LoadString(IDS_PS_NETUNREACHABLE);
		break;
	case CICMP::ipDestHostUnreachable:
		le.m_Status.LoadString(IDS_PS_HOSTUNREACHABLE);
		break;
	case CICMP::ipDestProtUnreachable:
		le.m_Status.LoadString(IDS_PS_PROTUNREACHABLE);
		break;
	case CICMP::ipDestPortUnreachable:
		le.m_Status.LoadString(IDS_PS_PORTUNREACHABLE);
	case CICMP::ipNoResources:
		le.m_Status.LoadString(IDS_PS_NORESOURCES);
		break;
	case CICMP::ipBadOption:
		le.m_Status.LoadString(IDS_PS_INTERNALERROR);
		break;
	case CICMP::ipHWError:
		le.m_Status.LoadString(IDS_PS_HWERROR);
		break;
	case CICMP::ipPacketTooBig:
		le.m_Status.LoadString(IDS_PS_BIGPACKET);
		break;
	case CICMP::ipTimeOut:
		le.m_Status.LoadString(IDS_PS_TIMEOUT);
		break;
	case CICMP::ipBadRequest:
		le.m_Status.LoadString(IDS_PS_INTERNALERROR);
		break;
	case CICMP::ipBadRoute:
		le.m_Status.LoadString(IDS_PS_BADROUTE);
		break;
	case CICMP::ipTTLExpiredInTransit:
		le.m_Status.LoadString(IDS_PS_TTLEXPTRANSIT);
		break;
	case CICMP::ipTTLExpiredInReasm:
		le.m_Status.LoadString(IDS_PS_TTLEXPREASM);
		break;
	case CICMP::ipParamProblem:
		le.m_Status.LoadString(IDS_PS_IPARAMP);
		break;
	case CICMP::ipSourceQuench:
		le.m_Status.LoadString(IDS_PS_SOURCEQUENCH);
		break;
	case CICMP::ipOptionTooBig:
		le.m_Status.LoadString(IDS_PS_BIGOPTION);
		break;
	case CICMP::ipBadDest:
		le.m_Status.LoadString(IDS_PS_BADDEST);
		break;
	default:
		le.m_Status.Format(IDS_PS_UNKNOWNERROR,status);
		break;
	}
goBye:
	if(pICMP) {
		pICMP->Deinitialize();
		delete pICMP;
	}
	if(le.m_bReached)
		m_bIsUp=TRUE;
	else{
		if(m_bIsUp)
			m_HowDown=0;
		m_bIsUp=FALSE;
		m_HowDown++;
	}

	le.m_Time=CTime::GetCurrentTime();

CLogEntry *newLE = NULL;
	if(!m_Log.IsEmpty()){
	CLogEntry *head = m_Log.GetHead();
		while(head && (m_bToKill?FALSE:(m_Doc->m_MaxLogTime<(le.m_Time-head->m_Time)))){
			m_Log.RemoveHead();
			if(newLE)
				delete head;
			else
				newLE=head;
			if(m_Log.IsEmpty())
				head=NULL;
			else
				head = m_Log.GetHead();
		}
	}
	if(newLE)
		(*newLE)=le;
	else
		newLE=new CLogEntry(le);
	m_Log.AddTail(newLE);

	if(m_bToKill)
		delete this;
	else{
		m_bPinged=TRUE;
		m_Pinged = CTime::GetCurrentTime();
		if(m_Doc)
			m_Doc->m_BBView->SendMessage(WM_ACTIVITYCOUNT,(WPARAM)-1,0);
		if(m_Doc)
			m_Doc->SetModifiedFlag();
		if(m_Doc)
			m_Doc->m_BBView->SendMessage(WM_UPDATETREEBROTHER,TRUE,(LPARAM)this);
	}
	return 0;
}

CLogEntry::CLogEntry()
{
	flags=0;
	m_bReached=FALSE;
	m_Status.Empty();
	m_Time=CTime::GetCurrentTime();
}

CBrother::~CBrother()
{
POSITION p = m_Log.GetHeadPosition();
	while(p){
	CLogEntry *le = m_Log.GetNext(p);
		delete le;
	}
	m_Log.RemoveAll();
}

void CBigBrotherDoc::CleanUp()
{
	if(m_BBView && m_BBView->m_Pages){
		m_BBView->m_Pages->SetBrother(NULL);
	}
	if(m_RootBrother){
		while(!m_Brotherhood.IsEmpty()){
		CBrother *b = m_Brotherhood.GetHead();
			ASSERT(b);
			b->m_Doc=this;
			b->Suicide();
		}
		m_RootBrother->m_Doc=this;
		m_RootBrother->Suicide();
		m_RootBrother=NULL;
	}
	m_MaxLogTime = CTimeSpan(0,1,0,0);
	m_MaxThreads = 5;
	m_PingSize = 32;
	m_bSaveOnShutdown = TRUE;
	m_AutoSave = CTimeSpan(0,0,30,0);
	m_AutoSaved = CTime::GetCurrentTime();
	flags=0;
}

CBrother* CBigBrotherDoc::GetCurrentBrother()
{
	if(m_BBView);
		return m_BBView->GetCurrentBrother();
	return NULL;
}

BOOL CBrother::IsValuable()
{
	return !m_Host.IsEmpty();
}

void CBigBrotherDoc::GetFamily(CBrother *b,CBrotherList *bh)
{
	ASSERT(b);
	ASSERT(bh);
	ASSERT(m_BBView);
	m_BBView->GetFamily(b,bh);
}

void CBigBrotherDoc::OnUpdateBrothersAddbrother(CCmdUI* pCmdUI) 
{
	ASSERT(m_BBView);
CBrother *bro = m_BBView->GetCurrentBrother();
	if(bro)
		pCmdUI->Enable(bro->m_Daddy!=NULL);
	else
		pCmdUI->Enable(FALSE);
}

void CBigBrotherDoc::OnBrothersAddbrother() 
{
	ASSERT(m_BBView);
CBrother *bro = m_BBView->GetCurrentBrother();
	ASSERT(bro);
	bro = bro->m_Daddy;
	ASSERT(bro);
CBrother *lb = new CBrother(bro);
	m_Brotherhood.AddTail(lb);
	SetModifiedFlag();
	m_BBView->AddBrother(lb);
	m_BBView->GotoBrother(lb);
}

BOOL CAction::PlayASound(LPCTSTR sound)
{
CString str;
	str.LoadString(IDS_ACTION_HOST_UP);
	if(!str.CompareNoCase(sound))
		return ::PlaySound((LPCTSTR)IDW_HOST_UP,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE);
	str.LoadString(IDS_ACTION_HOST_DOWN);
	if(!str.CompareNoCase(sound))
		return ::PlaySound((LPCTSTR)IDW_HOST_DOWN,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE);
	str.LoadString(IDS_ACTION_SYSTEM_OK);
	if(!str.CompareNoCase(sound))
		return MessageBeep(MB_ICONASTERISK);
	str.LoadString(IDS_ACTION_SYSTEM_CRITICAL);
	if(!str.CompareNoCase(sound))
		return MessageBeep(MB_ICONHAND);
	return ::PlaySound(sound,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_FILENAME);
}

CLogEntry& CLogEntry::operator=(CLogEntry& src)
{
	m_bReached=src.m_bReached;
	m_RTT=src.m_RTT;
	m_Status=src.m_Status;
	m_Time=src.m_Time;
	flags=src.flags;
	return *this;
}

CLogEntry::CLogEntry(CLogEntry& src)
{
	(*this)=src;
}

void CAction::PerformAction(CBrother *b)
{
	if(flags&flagsPlayASound)
		PlayASound(m_Sound);
	if(flags&flagsRunCustom){
	CString cmd = FormatLine(m_Custom,b);
		system(cmd);
	}
}

void CBrother::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	CObject::Serialize(ar);

CBigBrotherDoc *pDoc = (CBigBrotherDoc*)ar.m_pDocument;
	ASSERT(pDoc);
	ASSERT(pDoc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));

	if (ar.IsStoring())
	{
		if(pDoc->m_BBView && (pDoc->m_BBView->GetTreeCtrl().GetItemState(m_Item,TVIS_EXPANDED)&TVIS_EXPANDED))
			flags|=flagsExpandedTree;
		else
			flags&=~flagsExpandedTree;
		if(pDoc->GetCurrentBrother()==this)
			flags|=flagsCurrentBrother;
		else
			flags&=~flagsCurrentBrother;
		// Store to archive
		ar << (DWORD)this;
		ar << (DWORD)m_Daddy;
		ar << flags;
		ar << m_bLog;
		ar << m_Host;
		ar << m_Desc;
		ar << m_IntervalGood;
		ar << m_IntervalBad;
		ar << m_TimeOut;
		ar << m_Retries;
		ar << &m_Up;
		ar << &m_Down;
		if(pDoc->m_bStoreLastActivity)
			m_Log.Serialize(ar);
		else{
		CLogList tmp;
			tmp.Serialize(ar);
		}
	}else{
#ifndef	NDEBUG
		{
		CString tmp;
			tmp.Format("Bro-OSchema: %u\n",ar.GetObjectSchema());
			TRACE0(tmp);
		}
#endif
		// Read from archive
	DWORD dw;
		ar >> dw;
		pDoc->m_ThisMap[dw]=this;
		ar >> dw;
		if(dw){
			VERIFY(pDoc->m_ThisMap.Lookup(dw,m_Daddy));
		}else
			m_Daddy=NULL;
		ar >> flags;
		ar >> m_bLog;
		ar >> m_Host;
		ar >> m_Desc;
		ar >> m_IntervalGood;
		ar >> m_IntervalBad;
		ar >> m_TimeOut;
		ar >> m_Retries;
	CAction *act = NULL;
		ar >> act;
		m_Up = *act;
		delete act;
		act = NULL;
		ar >> act;
		m_Down = *act;
		delete act;
		m_Log.Serialize(ar);
		ParentalAdjust();
	}
}

void CAction::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		// Store to archive
		ar << flags;
		ar << m_Sound;
		ar << m_Custom;
	}else{
#ifndef	NDEBUG
		{
		CString tmp;
			tmp.Format("Act-OSchema: %u\n",ar.GetObjectSchema());
			TRACE0(tmp);
		}
#endif
		// Read from archive
		ar >> flags;
		ar >> m_Sound;
		ar >> m_Custom;
	}
}

void CLogEntry::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		// Store to archive
		ar << flags;
		ar << m_Time;
		ar << m_bReached;
		ar << m_RTT;
		ar << m_Status;
	}else{
	UINT schema = ar.GetObjectSchema();
		/*
#ifndef	NDEBUG
		{
		CString tmp;
			tmp.Format("Log-OSchema: %u\n",schema);
			TRACE0(tmp);
		}
#endif
		*/
		// Read from archive
		if(schema>=2){
			ar >> flags;
		}
		ar >> m_Time;
		ar >> m_bReached;
		ar >> m_RTT;
		ar >> m_Status;
	}
}

CBrother::CBrother()
{
	CleanUp();
	ParentalAdjust(TRUE);
}

void CBigBrotherDoc::OnUpdateBrothersDelete(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetCurrentBrother()!=NULL);
}

void CBigBrotherDoc::OnBrothersDelete() 
{
	ASSERT(m_BBView);
CBrother *b = GetCurrentBrother();
	ASSERT(b);
	m_BBView->KillBrother(b);
	SetModifiedFlag();
}

void CBrother::Suicide()
{
	ASSERT(m_Doc);
	ASSERT(m_Doc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
CBigBrotherDoc *pDoc = (CBigBrotherDoc*)m_Doc;
	if(pDoc->m_BBView && pDoc->m_BBView->m_Pages->m_Brother==this)
		pDoc->m_BBView->m_Pages->m_Brother=NULL;
POSITION p = pDoc->m_Brotherhood.Find(this);
	if(p)
		pDoc->m_Brotherhood.RemoveAt(p);
#ifndef	NDEBUG
	else{
		ASSERT(!m_Daddy);
	}
#endif
	m_Item=NULL;
	if(m_bPinging){
		m_bToKill=TRUE;
		m_Daddy=NULL;
		m_Doc=NULL;
	}else
		delete this;
}

BOOL CBrother::operator==(CBrother& b)
{
	if(flags!=b.flags)
		return FALSE;
	if(m_bLog!=b.m_bLog)
		return FALSE;
	if(m_Desc.Compare(b.m_Desc))
		return FALSE;
	if(m_Down!=b.m_Down)
		return FALSE;
	if(m_Host.Compare(b.m_Host))
		return FALSE;
	if(m_IntervalGood!=b.m_IntervalGood || m_IntervalBad!=b.m_IntervalBad)
		return FALSE;
	if(m_Retries!=b.m_Retries)
		return FALSE;
	if(m_TimeOut!=b.m_TimeOut)
		return FALSE;
	if(m_Up!=b.m_Up)
		return FALSE;
	return TRUE;
}

BOOL CBrother::operator!=(CBrother& b)
{
	return !((*this)==b);
}

BOOL CAction::operator==(CAction& a)
{
	if(flags!=a.flags)
		return FALSE;
	if(m_Custom.Compare(a.m_Custom))
		return FALSE;
	if(m_Sound.Compare(a.m_Sound))
		return FALSE;
	return TRUE;
}

BOOL CAction::operator!=(CAction& a)
{
	return !((*this)==a);
}

CBrother& CBrother::operator=(CBrother& b)
{
	flags=b.flags;
	m_bLog=b.m_bLog;
	m_Desc=b.m_Desc;
	m_Down=b.m_Down;
	m_Host=b.m_Host;
	m_IntervalGood=b.m_IntervalGood;
	m_IntervalBad=b.m_IntervalBad;
	m_Retries=b.m_Retries;
	m_TimeOut=b.m_TimeOut;
	m_Up=b.m_Up;
	return *this;
}

BOOL CBigBrotherDoc::SaveModified() 
{
	if(((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_bShuttingDown && m_bSaveOnShutdown){
		DoFileSave();
		((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_bShuttingDown = FALSE;
		return TRUE;
	}	
	return CDocument::SaveModified();
}

void CBrother::AppendSeparator()
{
CLogEntry *le = new CLogEntry();
	le->flags=CLogEntry::flagsSeparator;
	m_Log.AddTail(le);
}

void CBigBrotherDoc::OnFilePreferences() 
{
CPreferences prefs(AfxGetApp()->m_pMainWnd);
	prefs.m_AutosaveMinutes=m_AutoSave.GetTotalMinutes();
	prefs.m_LogFile=m_LogFile;
	prefs.m_MaxThreads=m_MaxThreads;
	prefs.m_PingSize=m_PingSize;
	prefs.m_SaveOnShutdown=m_bSaveOnShutdown;
	prefs.m_LogMins=m_MaxLogTime.GetTotalMinutes();
	prefs.m_bStoreLastActivity=m_bStoreLastActivity;
	if(prefs.DoModal()==IDOK){
		m_AutoSave = CTimeSpan(0,prefs.m_AutosaveMinutes/60,prefs.m_AutosaveMinutes%60,0);
		m_LogFile=prefs.m_LogFile;
		m_MaxThreads=prefs.m_MaxThreads;
		m_PingSize=prefs.m_PingSize;
		m_bSaveOnShutdown=prefs.m_SaveOnShutdown;
		m_MaxLogTime = CTimeSpan(0,prefs.m_LogMins/60,prefs.m_LogMins%60,0);
		m_bStoreLastActivity=prefs.m_bStoreLastActivity;
	}
}

void CBigBrotherDoc::LogLine(LPCTSTR str)
{
	if(!m_LogFile.IsEmpty()){
		TRY{
		CFile file(m_LogFile,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite|CFile::shareDenyWrite|CFile::typeBinary);
			file.SeekToEnd();
			file.Write(str,strlen(str));
			file.Write("\r\n",2);
			file.Close();
		}CATCH(CFileException, e){
#ifndef	NDEBUG
			afxDump << "Logging error: " << e->m_cause << "\n";
#endif
		}END_CATCH
	}
}

CString CAction::FormatLine(LPCTSTR fmt,CBrother *b)
{
	ASSERT(b);
CString str = fmt;
CString rv;
	while(!str.IsEmpty()){
	int pe = str.Find('%');
		if(pe<0){
			rv+=str;
			str.Empty();
		}else{
			rv+=str.Left(pe);
			str = str.Mid(pe+1);
			if(!str.IsEmpty()){
				switch(str[0]){
				case	'%':
					rv+="%";
					break;
				case	'h':
				case	'H':
					rv+=b->m_Host;
					break;
				case	'd':
				case	'D':
					rv+=b->m_Desc;
					break;
				}
				str=str.Mid(1);
			}else{
				rv+="%"+str;
				str.Empty();
			}
		}
	}
	return rv;
}

void CBigBrotherDoc::OnUpdateFilePause(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((flags&flagsSuspended)?1:0);
}

void CBigBrotherDoc::OnFilePause() 
{
	flags^=flagsSuspended;
	if(!(flags&flagsSuspended)){
		ASSERT(m_RootBrother);
		m_RootBrother->AppendSeparator();
	POSITION p = m_Brotherhood.GetHeadPosition();
		while(p){
		CBrother *b = m_Brotherhood.GetNext(p);
			ASSERT(b);
			b->AppendSeparator();
		}
		CheckPendingQueue();
	}else{
		ASSERT(m_BBView);
		m_BBView->KillTimer(TM_CHECK);
	}
}

void CBigBrotherDoc::DeleteContents() 
{
	CleanUp();	
	CDocument::DeleteContents();
}

void CBigBrotherDoc::OnCloseDocument() 
{
	CleanUp();
	CDocument::OnCloseDocument();
}

void CBigBrotherDoc::OnUpdateViewHostproperties(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((flags&flagsShowProps)?1:0);
}

void CBigBrotherDoc::OnViewHostproperties() 
{
	ASSERT(m_BBView);
	ASSERT(m_BBView->m_Pages);
	flags^=flagsShowProps;
	if(flags&flagsShowProps)
		m_BBView->m_Pages->ShowWindow(SW_SHOW);
	else
		m_BBView->m_Pages->ShowWindow(SW_HIDE);
}
