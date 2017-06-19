// Этот исходный код MFC Samples демонстрирует функционирование пользовательского интерфейса Fluent на основе MFC в Microsoft Office
// ("Fluent UI") и предоставляется исключительно как справочный материал в качестве дополнения к
// справочнику по пакету Microsoft Foundation Classes и связанной электронной документации,
// включенной в программное обеспечение библиотеки MFC C++. 
// Условия лицензионного соглашения на копирование, использование или распространение Fluent UI доступны отдельно. 
// Для получения дополнительных сведений о нашей лицензионной программе Fluent UI посетите веб-узел
// http://msdn.microsoft.com/officeui.
//
// (C) Корпорация Майкрософт (Microsoft Corp.)
// Все права защищены.

// WordView.cpp : реализация класса CWordView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Word.h"
#endif

#include "WordDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "WordView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWordView

IMPLEMENT_DYNCREATE(CWordView, CRichEditView)

BEGIN_MESSAGE_MAP(CWordView, CRichEditView)
	ON_WM_DESTROY()
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWordView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// создание/уничтожение CWordView

CWordView::CWordView()
{
	// TODO: добавьте код создания

}

CWordView::~CWordView()
{
}

BOOL CWordView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CWordView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Задайте границы печати (720 твип = 1/2 дюйма)
	SetMargins(CRect(720, 720, 720, 720));
}


// печать CWordView


void CWordView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWordView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}


void CWordView::OnDestroy()
{
	// Деактивируйте элемент при удалении; это важно
	// в случае использования представления разделителя
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CWordView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWordView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CWordView

#ifdef _DEBUG
void CWordView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CWordView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CWordDoc* CWordView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWordDoc)));
	return (CWordDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CWordView
