
// Thread2View.cpp : реализация класса CThread2View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Thread2.h"
#endif

#include "Thread2Doc.h"
#include "Thread2View.h"
#include "Thread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThread2View

IMPLEMENT_DYNCREATE(CThread2View, CView)

BEGIN_MESSAGE_MAP(CThread2View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CThread2View

CThread2View::CThread2View()
	: m_myThread(NULL)
{
	// TODO: добавьте код создания

}

CThread2View::~CThread2View()
{
}

BOOL CThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CThread2View

void CThread2View::OnDraw(CDC* /*pDC*/)
{
	CThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// печать CThread2View

BOOL CThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CThread2View

#ifdef _DEBUG
void CThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThread2Doc* CThread2View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThread2Doc)));
	return (CThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CThread2View


void CThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	
	DWORD exitcode; // переменная для состояния второго потока
	// если работает второй поток, его прерываем с помощью синхронизирующего события,
	// удаляем второй поток и запускаем его заново
	if (m_myThread) // если работает второй поток
	{
	   gExit.SetEvent(); // генерируем синхронизирующее событие
	   // дожидаемся прерывания работы второго потока
	   do
	     GetExitCodeThread(m_myThread->m_hThread, &exitcode); // получить состояние второго потока
		while (exitcode == STILL_ACTIVE);
	Invalidate();  // перерисовать окно
	UpdateWindow(); // обновить окно
	delete(m_myThread); 
	m_myThread = NULL; // удалить второй поток
	}
	// запускаем второй поток заново
    m_myThread = AfxBeginThread(Fractal, this, THREAD_PRIORITY_NORMAL);
	m_myThread->m_bAutoDelete = FALSE; // отключаем автоудаление второго потока
	CView::OnLButtonDown(nFlags, point);

}
