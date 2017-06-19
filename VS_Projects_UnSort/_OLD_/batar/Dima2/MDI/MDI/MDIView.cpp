
// MDIView.cpp : реализация класса CMDIView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MDI.h"
#endif

#include "MDIDoc.h"
#include "MDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDIView

IMPLEMENT_DYNCREATE(CMDIView, CView)

BEGIN_MESSAGE_MAP(CMDIView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CMDIView

CMDIView::CMDIView()
{
	// TODO: добавьте код создания

}

CMDIView::~CMDIView()
{
}

BOOL CMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMDIView

void CMDIView::OnDraw(CDC* pDC)
{
	CMDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CRect rect;
	GetClientRect(&rect);// определить размеры клиентской части окна
	COLORREF oldcolor;
	switch(pDoc->m_colour)
	{
		case 0:
			oldcolor = pDC->SetTextColor(RGB(0,0,0));
			break;
		case 1:
			oldcolor = pDC->SetTextColor(RGB(0,255,0));
			break;
		case 2:
			oldcolor = pDC->SetTextColor(RGB(255,0,0));
			break;
		case 3:
			oldcolor = pDC->SetTextColor(RGB(0,0,255));
			break;
    }

	int DTFlags = 0;
	if (pDoc->m_hcentre)
		DTFlags = DT_CENTER;
	if (pDoc->m_vcentre)
		DTFlags |= DT_VCENTER|DT_SINGLELINE;

	pDC->DrawText(pDoc->GetString(),&rect,DTFlags);
	pDC->SetTextColor(oldcolor);
}

// печать CMDIView

BOOL CMDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMDIView

#ifdef _DEBUG
void CMDIView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIDoc* CMDIView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIDoc)));
	return (CMDIDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMDIView
