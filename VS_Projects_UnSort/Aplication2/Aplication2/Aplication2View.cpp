
// Aplication2View.cpp : реализаци€ класса CAplication2View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Aplication2.h"
#endif

#include "Aplication2Doc.h"
#include "Aplication2View.h"
#include <cstring>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAplication2View

IMPLEMENT_DYNCREATE(CAplication2View, CView)

BEGIN_MESSAGE_MAP(CAplication2View, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CAplication2View

CAplication2View::CAplication2View()
{
	// TODO: добавьте код создани€

}

CAplication2View::~CAplication2View()
{
}

BOOL CAplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CAplication2View

CString ConCat(int a, int b)
{
	char str[10], str2[10];
	CString str3;
	itoa(a, str, 10);
	itoa(b, str2, 10);
	str3=strcat(str, str2);
	return str3;
}

	
void CAplication2View::OnDraw(CDC* pDC)
{
	CAplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT textRect;
	this->GetClientRect(&textRect);
	
	
	RECT rectan;
	/*rectan.top = 10;
	rectan.left=10;
	rectan.right=rectan.left+100;
	rectan.bottom=rectan.top+100;
	pDC->Rectangle(&rectan);
	pDC->TextOutA(rectan.left+30, rectan.top+40, ConCat(1, 2));*/

	
	/*for( int i =0 ; i<10; i++)
	{
		rectan.top = 10;
		rectan.left= 10+10*i + 100*i;
		rectan.right=rectan.left+100;
		rectan.bottom=rectan.top+100;
		pDC->Rectangle(&rectan);
		pDC->TextOutA(rectan.left+30, rectan.top+40, ConCat(i+1, 1));
	}*/
	RECT *rectangle = new RECT;
	GetClientRect(rectangle);
	//pDC->TextOutA(200, 150, ConCat((rectangle->right)/10, 1));
	//pDC->TextOutA(400, 150, ConCat((rectangle->left)/10, 1));


	for(int j=0; ((110*j)+120)<(rectangle->bottom); j++)
		for(int i=0; ((110*i)+120)<(rectangle->right); i++)
		{
			rectan.top = 110*j+10;
			rectan.left= 10 + 110*i;
			rectan.right=rectan.left+100;
			rectan.bottom=rectan.top+100;
			pDC->Rectangle(&rectan);
			pDC->TextOutA(rectan.left+30, rectan.top+40, ConCat(j+1, i+1));
		}
	

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CAplication2View

BOOL CAplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CAplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CAplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CAplication2View

#ifdef _DEBUG
void CAplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CAplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAplication2Doc* CAplication2View::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAplication2Doc)));
	return (CAplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CAplication2View
