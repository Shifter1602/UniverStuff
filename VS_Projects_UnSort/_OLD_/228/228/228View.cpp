
// 228View.cpp : реализация класса CMy228View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "228.h"
#endif

#include "228Doc.h"
#include "CntrItem.h"
#include "resource.h"
#include "228View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy228View

IMPLEMENT_DYNCREATE(CMy228View, CView)

BEGIN_MESSAGE_MAP(CMy228View, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &CMy228View::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &CMy228View::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &CMy228View::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CMy228View

CMy228View::CMy228View()
{
	m_pSelection = NULL;
	// TODO: добавьте код создания

}

CMy228View::~CMy228View()
{
}

BOOL CMy228View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMy228View

void CMy228View::OnDraw(CDC* pDC)
{
	if (!pDC)
		return;

	CMy228Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	// TODO: также нарисуйте все элементы OLE в документе

	// Отрисуйте выделенный фрагмент в произвольном месте. Этот код должен быть
	//  удален, поскольку реализован код отрисовки. Это положение
	//  точно соответствует прямоугольнику, возвращенному CMy228CntrItem,
	//  для предоставления возможности редактирования по месту.

	// TODO: удалите этот код после завершения вашего кода рисования.
	if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);
		
		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		m_pSelection->Draw(pDC, rect);
	}
}

void CMy228View::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: удалите этот код, когда финальный код модели выбора будет написан
	m_pSelection = NULL;    // инициализация выделения

}


// печать CMy228View

BOOL CMy228View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMy228View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMy228View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CMy228View::OnDestroy()
{
	// Деактивируйте элемент при удалении; это важно
	// в случае использования представления разделителя
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CView::OnDestroy();
}



// Команды и поддержка клиента OLE

BOOL CMy228View::IsSelected(const CObject* pDocItem) const
{
	// Реализация ниже справедлива, если выделенный фрагмент состоит
	//  только из объектов CMy228CntrItem. Чтобы управлять различными
	//  механизмами выбора следует заменить здесь реализацию

	// TODO: Реализуйте эту функцию, которая проверяет выбранный элемент клиента OLE

	return pDocItem == m_pSelection;
}

void CMy228View::OnInsertObject()
{
	// Откройте стандартное диалоговое окно "Вставка объекта" для получения информации
	//  для нового объекта CMy228CntrItem
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CMy228CntrItem* pItem = NULL;
	TRY
	{
		// Создать новый элемент, связанный с этим документом
		CMy228Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CMy228CntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Инициализируйте элемент из данных диалогового окна
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // любое исключение выполнит
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// Поскольку дизайн интерфейса пользователя произвольный, это задает вставку выделенного
		//  фрагмента в последний элемент

		// TODO: повторите реализацию выделения, как это требуется в приложении
		m_pSelection = pItem;   // выделение последнего вставленного элемента
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// Следующий обработчик команд предоставляет стандартный клавиатурный
//  интерфейс пользователя для отмены сеанса редактирования по месту. Здесь
//  контейнер (не сервер) вызывает деактивацию
void CMy228View::OnCancelEditCntr()
{
	// Закройте в этом представлении все активные объекты редактирования по месту
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Для контейнера требуется специальная обработка OnSetFocus и OnSize,
//  если объект редактируется по месту
void CMy228View::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// необходимо установить фокус на этот объект, если он находится в том же представлении
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // не вызывайте базовый класс
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void CMy228View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void CMy228View::OnFilePrint()
{
	//По умолчанию печать активного документа запрашивается
	//с помощью IOleCommandTarget. Если такое поведение не требуется,
	//удалите вызов COleDocObjectItem::DoDefaultPrinting.
	//Если вызов будет неудачным по какой-либо причине, мы попробуем напечатать
	//docobject с помощью интерфейса IPrint.
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}



// диагностика CMy228View

#ifdef _DEBUG
void CMy228View::AssertValid() const
{
	CView::AssertValid();
}

void CMy228View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy228Doc* CMy228View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy228Doc)));
	return (CMy228Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMy228View
