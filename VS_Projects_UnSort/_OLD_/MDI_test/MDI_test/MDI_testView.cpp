
// MDI_testView.cpp : реализаци€ класса CMDI_testView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MDI_test.h"
#endif

#include "MDI_testDoc.h"
#include "MDI_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDI_testView

IMPLEMENT_DYNCREATE(CMDI_testView, CView)

BEGIN_MESSAGE_MAP(CMDI_testView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CMDI_testView

CMDI_testView::CMDI_testView()
{
	// TODO: добавьте код создани€

}

CMDI_testView::~CMDI_testView()
{
}

BOOL CMDI_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMDI_testView

void CMDI_testView::OnDraw(CDC* /*pDC*/)
{
	CMDI_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CMDI_testView

BOOL CMDI_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMDI_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMDI_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMDI_testView

#ifdef _DEBUG
void CMDI_testView::AssertValid() const
{
	CView::AssertValid();
}

void CMDI_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDI_testDoc* CMDI_testView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDI_testDoc)));
	return (CMDI_testDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMDI_testView
