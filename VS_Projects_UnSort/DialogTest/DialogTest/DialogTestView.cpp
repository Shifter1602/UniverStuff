
// DialogTestView.cpp : implementation of the CDialogTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DialogTest.h"
#endif

#include "DialogTestDoc.h"
#include "DialogTestView.h"
#include "TextDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogTestView

IMPLEMENT_DYNCREATE(CDialogTestView, CView)

BEGIN_MESSAGE_MAP(CDialogTestView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CDialogTestView construction/destruction

CDialogTestView::CDialogTestView()
{
	// TODO: add construction code here

}

CDialogTestView::~CDialogTestView()
{
}

BOOL CDialogTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDialogTestView drawing

void CDialogTestView::OnDraw(CDC* /*pDC*/)
{
	CDialogTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CDialogTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDialogTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDialogTestView diagnostics

#ifdef _DEBUG
void CDialogTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogTestDoc* CDialogTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogTestDoc)));
	return (CDialogTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogTestView message handlers


void CDialogTestView::OnLButtonDown(UINT nFlags, CPoint point)
	{
	// TODO: Add your message handler code here and/or call default
	TextDialog aDlg;
	if(aDlg.DoModal()==IDOK)
		{
		CClientDC aDC(this);
		//вывод по щелчку на клавише ОК, поэтому создать текстовый элемент
		//получаем размер для текста
		CSize textExetent=aDC.GetTextExtent(aDlg.m_str);
		CRect rect(point,textExetent);//описывающий прямоугольник
		//рисуем текст
		aDC.DrawText(aDlg.m_str,rect,DT_CENTER|DT_VCENTER|
			DT_SINGLELINE|DT_NOCLIP);
		}

	CView::OnLButtonDown(nFlags, point);
	}
