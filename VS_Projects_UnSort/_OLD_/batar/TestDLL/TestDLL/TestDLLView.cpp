
// TestDLLView.cpp : реализация класса CTestDLLView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "TestDLL.h"
#endif

#include "TestDLLDoc.h"
#include "TestDLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestDLLView

IMPLEMENT_DYNCREATE(CTestDLLView, CView)

BEGIN_MESSAGE_MAP(CTestDLLView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CTestDLLView

CTestDLLView::CTestDLLView()
{
	// TODO: добавьте код создания

}

CTestDLLView::~CTestDLLView()
{
}

BOOL CTestDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CTestDLLView

void CTestDLLView::OnDraw(CDC* /*pDC*/)
{
	CTestDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// печать CTestDLLView

BOOL CTestDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CTestDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CTestDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CTestDLLView

#ifdef _DEBUG
void CTestDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CTestDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDLLDoc* CTestDLLView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDLLDoc)));
	return (CTestDLLDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CTestDLLView


void CTestDLLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	OnLeftButton(this, point);

	CView::OnLButtonDown(nFlags, point);
}


void CTestDLLView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	OnRightButton(this, point);
	CView::OnRButtonDown(nFlags, point);
}
