
// MDI1View.cpp : реализаци€ класса CMDI1View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MDI1.h"
#endif

#include "MDI1Doc.h"
#include "MDI1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDI1View

IMPLEMENT_DYNCREATE(CMDI1View, CView)

BEGIN_MESSAGE_MAP(CMDI1View, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CMDI1View

CMDI1View::CMDI1View()
{
	// TODO: добавьте код создани€

}

CMDI1View::~CMDI1View()
{
}

BOOL CMDI1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMDI1View

void CMDI1View::OnDraw(CDC* pDC)
{
	CMDI1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
	CRect rect;
	GetClientRect(&rect);//Define cllient frame size
	COLORREF oldcolor;
	/*switch(pDoc->m_color)
	{
		case 0:
			oldcolor = pDC->SetTextColor(RGB(0,0,0));
			break;
		case 1:
			oldcolor = pDC->SetTextColor(RGB(255,0,0));
			break;
		case 2:
			oldcolor = pDC->SetTextColor(RGB(0,255,0));
			break;
		case 3:
			oldcolor = pDC->SetTextColor(RGB(0,0,255));
			break;
	}
	int DTFlags = 0;
	if(pDoc->m_hcenter)
		DTFlags = DT_CENTER;
	if(pDoc->m_vcenter)
		DTFlags |= DT_VCENTER | DT_SINGLELINE;
	
	pDC->DrawText(pDoc->GetString(),&rect,DTFlags);
	pDC->SetTextColor(oldcolor);*/
}


// печать CMDI1View

BOOL CMDI1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMDI1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMDI1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMDI1View

#ifdef _DEBUG
void CMDI1View::AssertValid() const
{
	CView::AssertValid();
}

void CMDI1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDI1Doc* CMDI1View::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDI1Doc)));
	return (CMDI1Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMDI1View
