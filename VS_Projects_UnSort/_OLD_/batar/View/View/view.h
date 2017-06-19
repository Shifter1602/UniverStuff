#include <afxwin.h>

class CMyView: public CView
{
public:
	CMyView (CFrameWnd*parent);
	afx_msg void OnLButtonDown (UINT Flags, CPoint point);
	afx_msg void OnRButtonDown (UINT Flags, CPoint point);
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnDraw (class CDC*);

};

class CMyFrameWnd: public CFrameWnd
{
public:
	CMyFrameWnd();
};

class CMyApp: public CWinApp
{
public:
	virtual BOOL InitInstance();
};