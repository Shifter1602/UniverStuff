#include "view2.h"
using namespace std;
CMyApp app;

CMyView::CMyView (CFrameWnd*parent)
{
	Create (0,0, WS_CHILD | WS_VISIBLE, CRect(), parent, AFX_IDW_PANE_FIRST);
};


void CMyView::OnDraw (class CDC*dc)
{
	RECT rect;
	TEXTMETRIC tm;
	GetClientRect (&rect);
	dc -> GetTextMetrics (&tm);
	dc -> TextOut (10, (rect.bottom - tm.tmHeight)/2, "Ёто окно представлени€");
}

CMyFrameWnd::CMyFrameWnd()
{
	Create (0, "ќкно с представлением", WS_OVERLAPPEDWINDOW, CRect (20,20, 400, 300));
	new CMyView (this);
}

BOOL CMyApp::InitInstance()
{
	CMyFrameWnd*pMainWnd = new CMyFrameWnd;
	m_pMainWnd = pMainWnd;
	m_pMainWnd -> ShowWindow (m_nCmdShow);
	m_pMainWnd -> UpdateWindow();
	return TRUE;
}

void CMyView::OnLButtonDown (UINT Flags, CPoint point)
{
	CClientDC dc (this);
	dc. Rectangle (int (point.x)-50, int (point.y)-40, int (point.x)+50, int (point.y)+40);
	dc. Rectangle (int (point.x)-35, int (point.y)-15, int (point.x)+5, int (point.y)+15);
	dc. Rectangle (int (point.x)-35, int (point.y)-1, int (point.x)+5, int (point.y)+15);
	dc. Rectangle (int (point.x)-15, int (point.y)-15, int (point.x)+5, int (point.y));
	dc. Rectangle (int (point.x)+44, int (point.y)-10, int (point.x)+10, int (point.y)+40);
	dc. Rectangle (int (point.x)-35, int (point.y)-1, int (point.x)-14, int (point.y+15));
	dc. MoveTo (int (point.x), int (point.y)-110);
	dc. LineTo (int (point.x)-50, int (point.y)-40);
	dc. MoveTo (int (point.x), int (point.y)-110);
	dc. LineTo (int (point.x)+50, int (point.y)-40);



}

void CMyView::OnRButtonDown (UINT Flags, CPoint point)
{
	CClientDC dc (this);
	dc. Ellipse (int (point.x)-30, int (point.y)-50, int (point.x)+10, int (point.y)+10);
}

BEGIN_MESSAGE_MAP (CMyView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	END_MESSAGE_MAP()

