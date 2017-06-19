#include <afxwin.h>
#include <afxext.h>

class CView1: public CView
{
public:
	DECLARE_DYNCREATE (CView1);
	afx_msg void OnLButtonDown (UINT Flags, CPoint point);
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnDraw (class CDC*);
};

class CView2: public CView
{
public:
	DECLARE_DYNCREATE (CView2);
	afx_msg void OnRButtonDown (UINT Flags, CPoint point);
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnDraw (class CDC*);
};

class CView3: public CView
{
public:
	DECLARE_DYNCREATE (CView3);
	afx_msg void OnRButtonDown (UINT Flags, CPoint point);
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnDraw (class CDC*);
};


class CMyFrameWnd: public CFrameWnd
{
public:
	CMyFrameWnd();
protected:
	DECLARE_MESSAGE_MAP()
	void OnNcLButtonDown (UINT, CPoint);
};

class CMyApp: public CWinApp
{
	virtual BOOL InitInstance();
};





















