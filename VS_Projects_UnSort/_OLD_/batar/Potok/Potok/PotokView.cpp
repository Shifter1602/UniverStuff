
// PotokView.cpp : реализаци€ класса CPotokView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Potok.h"
#endif

#include "PotokDoc.h"
#include "PotokView.h"
#include <complex> // подключаем библиотеку дл€ работы с комплексными числами
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPotokView

IMPLEMENT_DYNCREATE(CPotokView, CView)

BEGIN_MESSAGE_MAP(CPotokView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CPotokView

CPotokView::CPotokView()
{
	// TODO: добавьте код создани€

}

CPotokView::~CPotokView()
{
}

BOOL CPotokView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CPotokView

void CPotokView::OnDraw(CDC* /*pDC*/)
{
	CPotokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать CPotokView

BOOL CPotokView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CPotokView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CPotokView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CPotokView

#ifdef _DEBUG
void CPotokView::AssertValid() const
{
	CView::AssertValid();
}

void CPotokView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPotokDoc* CPotokView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPotokDoc)));
	return (CPotokDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CPotokView


void CPotokView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// запускаем длительную задачу в основном потоке
	CClientDC dc(this); // получаем контекст клиентской части окна представлени€
	RECT rect; // пр€моугольник дл€ вычислени€ размера окна
	GetClientRect(&rect); // вычисл€ем и запоминаем размеры окна представлени€
	complex<double> c(-0.012, 0.74); // константа комплексного числа
	for (int i=rect.left; i<rect.right; i++)
		for (int j=rect.top; i<rect.bottom; j++)
		{
		   complex<double> x(0.0001*i, 0.0001*j);
		   for (int n=0; n<100; n++)
		   {
			   if (abs(x)>100) break;
			   else x=pow(x,2)+c;
		   if (abs(x)<1)
			   dc.SetPixel(i,j,RGB(0,0,255));
		   else dc.SetPixel(i,i,RGB(2*abs(x),255,255));
		}
		}
	CView::OnLButtonDown(nFlags, point);
}
