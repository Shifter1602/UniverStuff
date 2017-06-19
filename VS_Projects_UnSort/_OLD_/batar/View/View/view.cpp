#include "view.h"
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
