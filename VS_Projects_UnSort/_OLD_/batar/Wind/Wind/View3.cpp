#include "View3.h"
CMyApp app;
IMPLEMENT_DYNCREATE(CView1,CView);
void CView1::OnDraw(class CDC*dc)
{
	dc->TextOut(10,10,"Это первое представление");
}

IMPLEMENT_DYNCREATE(CView2,CView);
void CView2::OnDraw(class CDC*dc)
{
	dc->TextOut(10,10,"Это второе представление");
}

CMyFrameWnd::CMyFrameWnd()
{
	Create(0,"Приложение с двумя представлениями", WS_OVERLAPPEDWINDOW, CRect(20,20,600,400));
	CCreateContext context;
	context.m_pCurrentDoc=NULL;
	context.m_pNewViewClass=RUNTIME_CLASS(CView1);
	CView*pNewView=STATIC_DOWNCAST(CView,CreateView(&context));
	if(pNewView!=NULL)
	{
		SetActiveView(pNewView);
		pNewView->ShowWindow(SW_SHOWNORMAL);
	}
}
	void CMyFrameWnd::OnNcLButtonDown(UINT flags,CPoint point)
	{
		CView*pActiveView=GetActiveView();
		CView*pNewView;
		if(pActiveView->IsKindOf(RUNTIME_CLASS(CView1)))
		{
			pNewView=(CView*) new CView2;
		}
		else
		{
			pNewView=(CView*) new CView1;
		}
		CCreateContext context;
context.m_pCurrentDoc=pActiveView->GetDocument();
pNewView->Create(0,0,WS_BORDER,CFrameWnd::rectDefault,this,0,&context);
if(pNewView!=NULL)
{
	SetActiveView(pNewView);
	pActiveView->DestroyWindow();
	pNewView->ShowWindow(SW_SHOWNORMAL);
	pNewView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
}
	RecalcLayout();
}
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_NCLBUTTONDOWN()
	WND_MESSAGE_MAP()
	END_MESSAGE_MAP()

	BOOL CMyApp::InitInstance()
	{
		CMyFrameWnd*pMainWnd = new CMyFrameWnd;
		m_pMainWnd=pMainWnd;
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}
	