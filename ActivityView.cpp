// ActivityView.cpp : implementation file
//

#include "stdafx.h"
#include "BigBrother.h"
#include "ActivityView.h"

#include "BigBrotherDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CActivityView

IMPLEMENT_DYNCREATE(CActivityView, CScrollView)

CActivityView::CActivityView()
{
	m_Background = GetSysColor(COLOR_MENU);
	//RGB(128,255,128);
	m_BoxColor = RGB(192,255,255);
	m_Red = RGB(255,0,0);
	m_Green = RGB(0,192,0);
	m_Yellow = RGB(255,255,0);
	m_Dim = RGB(192,192,192);
	m_Brothers = new CBrotherList;
}

CActivityView::~CActivityView()
{
	delete m_Brothers;
}


BEGIN_MESSAGE_MAP(CActivityView, CScrollView)
	//{{AFX_MSG_MAP(CActivityView)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CActivityView drawing

void CActivityView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	OnUpdate(NULL,0,NULL);
}

void CActivityView::OnDraw(CDC* pDC)
{
CBigBrotherDoc* pDoc = (CBigBrotherDoc*)GetDocument();
	if(!pDoc)
		return;
	ASSERT(pDoc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
	if(m_Brothers->IsEmpty())
		return;
BOOL bt = FALSE, et=FALSE;
BOOL isAny = FALSE;
CTime beginTime, endTime;
POSITION p = m_Brothers->GetHeadPosition();
	while(p){
	CBrother *b = m_Brothers->GetNext(p);
		ASSERT(b);
		if(b->m_Log.IsEmpty())
			continue;
		isAny=TRUE;
		if((!bt) || b->m_Log.GetHead()->m_Time<beginTime){
			bt=TRUE;
			beginTime=b->m_Log.GetHead()->m_Time;
		}
		if((!et) || b->m_Log.GetTail()->m_Time>endTime){
			et=TRUE;
			endTime=b->m_Log.GetTail()->m_Time;
		}
	}
	if(!isAny){
		m_bPainted=FALSE;
		return;
	}
	m_bPainted=TRUE;
CTimeSpan ts = endTime-beginTime;
	if(ts<pDoc->m_MaxLogTime)
		ts = pDoc->m_MaxLogTime;
	m_BeginTime=beginTime;
	m_TimeSpan=ts;
	p = m_Brothers->GetHeadPosition();
int host = 0;
	while(p){
	CBrother *b = m_Brothers->GetNext(p);
		ASSERT(b);
	CRect rc(10,20+host*105,10+500,20+host*105+100);
		pDC->FillSolidRect(rc,m_BoxColor);
		PaintHost(b,pDC,rc,&beginTime,&ts);
		host++;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CActivityView diagnostics

#ifdef _DEBUG
void CActivityView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CActivityView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CActivityView message handlers

void CActivityView::PaintHost(CBrother *b,CDC *pDC,CRect& rc,CTime *bTime,CTimeSpan *tSpan)
{
	ASSERT(b);
	if(b->m_Log.IsEmpty())
		return;
CBigBrotherDoc* pDoc = (CBigBrotherDoc*)GetDocument();
	ASSERT(pDoc);
	ASSERT(pDoc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
ULONG	rttMax = b->m_TimeOut;
CTime beginTime;
CTimeSpan ts;
	if(bTime && tSpan){
		beginTime= *bTime;
		ts = *tSpan;
	}else{
		beginTime = b->m_Log.GetHead()->m_Time;
	CTime endTime = b->m_Log.GetTail()->m_Time;
		ts = endTime-beginTime;
		if(ts<pDoc->m_MaxLogTime)
			ts = pDoc->m_MaxLogTime;
	}
POSITION	p = b->m_Log.GetHeadPosition();
	ASSERT(p);
CLogEntry *le = b->m_Log.GetNext(p);
	ASSERT(le);
int	x = rc.left+(le->m_Time-beginTime).GetTotalSeconds()*rc.Width()/ts.GetTotalSeconds();
	while(p){
		le = b->m_Log.GetNext(p);
		ASSERT(le);
	int newx=rc.left+(le->m_Time-beginTime).GetTotalSeconds()*rc.Width()/ts.GetTotalSeconds();
		if(!(le->flags&CLogEntry::flagsSeparator)){
		UINT	size = le->m_bReached?min(rttMax,le->m_RTT):rttMax;
		int	drawSize=(rttMax-size)*rc.Height()/rttMax;
		COLORREF color=le->m_bReached?((size<(rttMax/3))?m_Green:((size<(rttMax*2/3))?m_Yellow:m_Red)):m_Dim;
			pDC->FillSolidRect(x,rc.bottom-drawSize,newx-x,drawSize,color);
		}
		x=newx;
	}
}

void CActivityView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
CBigBrotherDoc* pDoc = (CBigBrotherDoc*)GetDocument();
	if(!pDoc)
		return;
	ASSERT(pDoc->IsKindOf(RUNTIME_CLASS(CBigBrotherDoc)));
	if(pHint){
	CBrother *b = (CBrother*)pHint;
		if(m_Brothers->Find(b)){
		CClientDC dc(this);
			OnPrepareDC(&dc);
		CRect rc = b->m_rc;
			dc.LPtoDP(&rc);
			InvalidateRect(rc,FALSE);
		}
		return;
	}
	m_Brothers->RemoveAll();
CBrother *b = pDoc->GetCurrentBrother();
	if(b)
		pDoc->GetFamily(b,m_Brothers);
	SetScaleToFitSize(CSize(10+500+10,20+m_Brothers->GetCount()*105+20));
POSITION p = m_Brothers->GetHeadPosition();
int host = 0;
	while(p){
	CBrother *b = m_Brothers->GetNext(p);
		b->m_rc.SetRect(10,20+host*105,10+500,20+host*105+100);
		host++;
	}
	CScrollView::OnUpdate(pSender,lHint,pHint);	
}

BOOL CActivityView::OnEraseBkgnd(CDC* pDC) 
{
CRect rc;
	GetClientRect(rc);
	pDC->FillSolidRect(rc,m_Background);
	return TRUE;
}

int CActivityView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_ToolTip.Create(this);
	m_ToolTip.Activate(TRUE);
	m_ToolTip.AddTool(this,IDS_AVIEW_NOTIP);

	return 0;
}

BOOL CActivityView::PreTranslateMessage(MSG* pMsg) 
{
	m_ToolTip.RelayEvent(pMsg);
	return CScrollView::PreTranslateMessage(pMsg);
}

void CActivityView::OnMouseMove(UINT nFlags, CPoint point) 
{
	UpdateTip(nFlags,point);
	CScrollView::OnMouseMove(nFlags, point);
}

void CActivityView::UpdateTip(UINT nFlags,CPoint point)
{
CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);
POSITION p = m_Brothers->GetHeadPosition();
	while(p){
	CBrother *b = m_Brothers->GetNext(p);
		if(b->m_rc.PtInRect(point)){
		CString tmp;
			tmp.Format(IDS_AVIEW_SHORTTIP,(LPCTSTR)b->m_Desc,(LPCTSTR)b->m_Host);
			if(m_bPainted && (nFlags&(MK_LBUTTON|MK_CONTROL|MK_SHIFT))){
			CTime theTime = m_BeginTime + CTimeSpan((point.x-b->m_rc.left)*m_TimeSpan.GetTotalSeconds()/b->m_rc.Width());
				if(nFlags&(MK_LBUTTON|MK_CONTROL)){
					// Add Time
					tmp += ", "+theTime.Format(IDS_AVIEW_TIP_TIMEFORMAT);
				}
				if(nFlags&MK_SHIFT){
					// Add RTT report
				CLogEntry *le = NULL;
				POSITION p = b->m_Log.GetTailPosition();
					while(p){
					CLogEntry *l = b->m_Log.GetPrev(p);
						if(theTime<l->m_Time)
							le = l;
						else
							break;
					}
				CString ttmp;
					if(le){
						if(le->m_bReached)
							ttmp.Format(IDS_AVIEW_TIP_RTTREPORT, le->m_RTT);
						else
							ttmp.LoadString(IDS_AVIEW_TIP_UNREACHABLE);
					}else
						ttmp.LoadString(IDS_AVIEW_TIP_UNPINGED);
					tmp += ", "+ttmp;
				}
			}
			m_ToolTip.Activate(TRUE);
			m_ToolTip.UpdateTipText(tmp,this);
			return;
		}
	}
	m_ToolTip.Activate(FALSE);
	m_ToolTip.UpdateTipText(IDS_AVIEW_NOTIP,this);
}

void CActivityView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	UpdateTip(nFlags,point);
	CScrollView::OnLButtonDown(nFlags, point);
}

void CActivityView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	UpdateTip(nFlags,point);
	CScrollView::OnLButtonUp(nFlags, point);
}

void CActivityView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
CDocument *pDoc = GetDocument();
	ASSERT(pDoc);
	pDoc->UpdateAllViews(NULL);
}
