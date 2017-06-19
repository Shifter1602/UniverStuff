
// Thread1View.cpp : реализаци€ класса CThread1View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Thread1.h"
#endif

#include "Thread1Doc.h"
#include "Thread1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThread1View

IMPLEMENT_DYNCREATE(CThread1View, CView)

BEGIN_MESSAGE_MAP(CThread1View, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CThread1View

CThread1View::CThread1View()
{
	// TODO: добавьте код создани€

}

CThread1View::~CThread1View()
{
}

BOOL CThread1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CThread1View

void CThread1View::OnDraw(CDC* /*pDC*/)
{
	CThread1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CThread1View

BOOL CThread1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CThread1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CThread1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CThread1View

#ifdef _DEBUG
void CThread1View::AssertValid() const
{
	CView::AssertValid();
}

void CThread1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThread1Doc* CThread1View::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThread1Doc)));
	return (CThread1Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CThread1View
