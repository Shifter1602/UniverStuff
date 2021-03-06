#include "View2.h"

CMyApp app;
IMPLEMENT_DYNCREATE (CView1, CView);
void CView1::OnDraw (class CDC*dc)
{
	dc -> TextOut (10,10, "��� ������ �������������");
}

IMPLEMENT_DYNCREATE (CView2, CView);
void CView2::OnDraw (class CDC*dc)
{
	dc -> TextOut (10,10, "��� ������ �������������");
}

IMPLEMENT_DYNCREATE (CView3, CView);
void CView3::OnDraw (class CDC*dc)
{
	dc -> TextOut (10,10, "��� ������ �������������");
}


CMyFrameWnd::CMyFrameWnd()
{
	Create (0, "���������� � ����� ���������������", WS_OVERLAPPEDWINDOW, CRect (20, 20, 600, 400));
	CCreateContext context;
	context. m_pCurrentDoc = NULL;
	context. m_pNewViewClass = RUNTIME_CLASS (CView1);
	CView*pNewView = STATIC_DOWNCAST (CView, CreateView (&context));

	if (pNewView != NULL)
	{
		SetActiveView (pNewView);
		pNewView -> ShowWindow (SW_SHOWNORMAL);
	}
}

void CMyFrameWnd::OnNcLButtonDown (UINT flags, CPoint point)
{
	CView*pActiveView = GetActiveView();
	CView*pNewView;
	if (pActiveView -> IsKindOf (RUNTIME_CLASS (CView1)))
	{
		pNewView = (CView*) new CView2;
	}
	else 
	{
		pNewView = (CView*) new CView1;
	}
	if (pActiveView -> IsKindOf (RUNTIME_CLASS (CView2)))
	{
		pNewView = (CView*) new CView3;
	}

	CCreateContext context;
	context. m_pCurrentDoc = pActiveView -> GetDocument();
	pNewView -> Create (0, 0, WS_BORDER, CFrameWnd::rectDefault, this, 0, &context);

	if (pNewView !=NULL)
	{
		SetActiveView (pNewView);
		pActiveView -> DestroyWindow();
		pNewView -> ShowWindow(SW_SHOWNORMAL);
		pNewView -> SetDlgCtrlID (AFX_IDW_PANE_FIRST);
	}
	RecalcLayout();
}

	void CView1::OnLButtonDown (UINT Flags, CPoint point)
{
	CClientDC dc (this);
	dc. Ellipse (int (point.x)-15, int (point.y)-15, int (point.x)+15, int (point.y)+15);
}
	void CView2::OnRButtonDown (UINT Flags, CPoint point)
{
	CClientDC dc (this);
	dc. Rectangle (int (point.x)-30, int (point.y)-30, int (point.x)+30, int (point.y)+30);
}
	void CView3::OnRButtonDown (UINT Flags, CPoint point)
{
	CClientDC dc (this);
	dc. Rectangle (int (point.x)-20, int (point.y)-30, int (point.x)+40, int (point.y)+50);
}
	BEGIN_MESSAGE_MAP (CView1, CView)
	ON_WM_LBUTTONDOWN()
	END_MESSAGE_MAP()

	BEGIN_MESSAGE_MAP (CView2, CView)
	ON_WM_RBUTTONDOWN()
	END_MESSAGE_MAP()

	BEGIN_MESSAGE_MAP (CView3, CView)
	ON_WM_RBUTTONDOWN()
	END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP (CMyFrameWnd, CFrameWnd)
	ON_WM_NCLBUTTONDOWN()
	END_MESSAGE_MAP()

	BOOL CMyApp::InitInstance()
	{
		CMyFrameWnd*pMainWnd = new CMyFrameWnd;
		m_pMainWnd = pMainWnd;
		m_pMainWnd -> ShowWindow (m_nCmdShow);
		m_pMainWnd -> UpdateWindow();
		return TRUE;
	}
