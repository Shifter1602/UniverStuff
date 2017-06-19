#include <afxwin.h>
#include <afxext.h>
class CView1:public CView
{
public:
	DECLARE_DYNCREATE(CView1);
protected:
	afx_msg void OnDraw(class CDC*);
};

class CView2:public CView
{
public:
	DECLARE_DYNCREATE(CView2);
protected:
	afx_msg void OnDraw(class CDC*);
};

class CMyFrameWnd:public CFrameWnd
{
public:
	CMyFrameWnd();
protected:
	DECLARE_MESSAGE_MAP()
    void OnNcLButtonDown(UINT,CPoint);
	
	class CMyApp:public CWinApp
	{
	public:
		virtual BOOL InitInstance();
	};