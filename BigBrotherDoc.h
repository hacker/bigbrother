// BigBrotherDoc.h : interface of the CBigBrotherDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CLogEntry : public CObject {
public:
	enum	{
		flagsSeparator=1
	};
	UINT flags;
	virtual void Serialize(CArchive& ar);
	CLogEntry(CLogEntry& src);
	CLogEntry& operator=(CLogEntry& src);
	BOOL m_bReached;
	CString m_Status;
	ULONG m_RTT;
	CTime m_Time;

	CLogEntry();
	DECLARE_SERIAL(CLogEntry)
};

typedef	CTypedPtrList<CObList,CLogEntry*>	CLogList;

class CBrother;
class CAction	: public CObject {
public:
	static CString FormatLine(LPCTSTR fmt,CBrother *b);
	BOOL operator!=(CAction& a);
	BOOL operator==(CAction& a);
	virtual void Serialize(CArchive& ar);
	void PerformAction(CBrother *b);
	static BOOL PlayASound(LPCTSTR sound);
	CAction& operator=(CAction& src);
	void CleanUp();
	enum	{
		flagsPlayASound = 1,
		flagsRunCustom = 2
	};
	UINT flags;
	CString m_Sound;
	CString m_Custom;

	CAction();
	DECLARE_SERIAL(CAction)
};

class CBrother	: public CObject	{
public:
	void AppendSeparator();
	CBrother& operator=(CBrother& b);
	BOOL operator!=(CBrother& b);
	BOOL operator==(CBrother& b);
	BOOL m_bToKill;
	void Suicide();
	virtual void Serialize(CArchive& ar);
	BOOL m_bUp;
	CRect m_rc;
	BOOL IsValuable();
	~CBrother();
	UINT m_HowDown;
	BOOL m_bPinging;
	UINT Check();
	CDocument* m_Doc;
	static UINT DoCheck(LPVOID pParam);
	BOOL m_bIsUp;
	BOOL m_bPending;
	CTime m_Pinged;
	BOOL m_bPinged;
	CLogList m_Log;
	HTREEITEM m_Item;
	void ParentalAdjust(BOOL cleanUp=FALSE);
	void CleanUp();
	CBrother(CBrother* daddy);
	CBrother* m_Daddy;
	UINT m_Retries;
	DWORD m_TimeOut;
	UINT m_IntervalBad;
	UINT m_IntervalGood;
	BOOL m_bLog;
	CAction m_Down;
	CAction m_Up;
	enum	{
		flagsOverrideIntervals=1,
		flagsOverrideTimeout=2,
		flagsOverrideRetries=4,
		flagsOverrideActions=8,
		flagsOverrideLogging=16,
		flagsExpandedTree=32,
		flagsCurrentBrother=64
	};
	UINT flags;
	CString m_Desc;
	CString m_Host;

	CBrother();
	DECLARE_SERIAL(CBrother)
};

typedef	CTypedPtrList<CObList,CBrother*>	CBrotherList;
typedef	CMap<DWORD,DWORD,CBrother*,CBrother*>	CThisMap;

class CBigBrotherView;
class CActivityView;
class CBigBrotherDoc : public CDocument
{
protected: // create from serialization only
	CBigBrotherDoc();
	DECLARE_SERIAL(CBigBrotherDoc)

// Attributes
public:
	BOOL m_bStoreLastActivity;
	enum	{
		flagsSuspended=1,
		flagsShowProps=2
	};
	UINT flags;
	CTime m_AutoSaved;
	void LogLine(LPCTSTR str);
	CTimeSpan m_AutoSave;
	BOOL m_bSaveOnShutdown;
	CThisMap m_ThisMap;
	CString m_LogFile;
	void GetFamily(CBrother *b,CBrotherList *bh);
	CBrother* GetCurrentBrother();
	void CleanUp();
	UINT m_PingSize;
	int m_MaxThreads;
	int m_Threads;
	void TryBrother(CBrother *b);
	BOOL CheckPendingBrother(CBrother* b,CTime& currentTime,CTime& nearestCheck,BOOL nearested);
	void CheckPendingQueue();
	CTimeSpan m_MaxLogTime;
	CActivityView *m_AView;
	CBigBrotherView* m_BBView;
	CBrotherList m_Brotherhood;
	CBrother* m_RootBrother;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBigBrotherDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void OnChangedViewList();
	virtual void DeleteContents();
	virtual void OnCloseDocument();
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBigBrotherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBigBrotherDoc)
	afx_msg void OnBrothersNew();
	afx_msg void OnUpdateBrothersAddbrother(CCmdUI* pCmdUI);
	afx_msg void OnBrothersAddbrother();
	afx_msg void OnUpdateBrothersDelete(CCmdUI* pCmdUI);
	afx_msg void OnBrothersDelete();
	afx_msg void OnFilePreferences();
	afx_msg void OnUpdateFilePause(CCmdUI* pCmdUI);
	afx_msg void OnFilePause();
	afx_msg void OnUpdateViewHostproperties(CCmdUI* pCmdUI);
	afx_msg void OnViewHostproperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
