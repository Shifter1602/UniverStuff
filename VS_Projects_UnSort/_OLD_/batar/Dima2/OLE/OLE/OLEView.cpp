
// OLEView.cpp : реализация класса COLEView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "OLE.h"
#endif

#include "OLEDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "OLEView.h"
#include "OptionsDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COLEView

IMPLEMENT_DYNCREATE(COLEView, CView)

BEGIN_MESSAGE_MAP(COLEView, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &COLEView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &COLEView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &COLEView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDBLCLK()

END_MESSAGE_MAP()

// создание/уничтожение COLEView

COLEView::COLEView()
{
	m_pSelection = NULL;
	// TODO: добавьте код создания

}

COLEView::~COLEView()
{
}

BOOL COLEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование COLEView

void COLEView::OnDraw(CDC* pDC)
{
	COLEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	// TODO: также нарисуйте все элементы OLE в документе

	// Отрисуйте выделенный фрагмент в произвольном месте. Этот код должен быть
	//  удален, поскольку реализован код отрисовки. Это положение
	//  точно соответствует прямоугольнику, возвращенному COLECntrItem,
	//  для предоставления возможности редактирования по месту.

	// TODO: удалите этот код после завершения вашего кода рисования.
	/*
	if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10,10,210,210);
		
		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		*/
	    
	    CRect rect;
	    GetClientRect(&rect);
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


	    POSITION pos = pDoc->GetStartPosition();
		while (pos)
		{
		COLECntrItem* pCurrentItem = (COLECntrItem*) pDoc->GetNextClientItem(pos);
		pCurrentItem->Draw(pDC, pCurrentItem->m_rect); // нарисовать следующий объект в коллекции
		// если объект является выделенным, рисуем трассирующую рамку
		if (pCurrentItem == m_pSelection)
		{
		CRectTracker tracker; // объявляем экземляр трассирующей рамки
		SetupTracker(m_pSelection, &tracker); // вызываем нашу функцию для подготовки вида трассирующей рамки
		tracker.Draw(pDC); // нарисовать трассирующую рамку
		}
	}
}

void COLEView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: удалите этот код, когда финальный код модели выбора будет написан
	m_pSelection = NULL;    // инициализация выделения

}


// печать COLEView

BOOL COLEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void COLEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void COLEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void COLEView::OnDestroy()
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

BOOL COLEView::IsSelected(const CObject* pDocItem) const
{
	// Реализация ниже справедлива, если выделенный фрагмент состоит
	//  только из объектов COLECntrItem. Чтобы управлять различными
	//  механизмами выбора следует заменить здесь реализацию

	// TODO: Реализуйте эту функцию, которая проверяет выбранный элемент клиента OLE

	return pDocItem == m_pSelection;
}

void COLEView::OnInsertObject()
{
	// Откройте стандартное диалоговое окно "Вставка объекта" для получения информации
	//  для нового объекта COLECntrItem
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	COLECntrItem* pItem = NULL;
	TRY
	{
		// Создать новый элемент, связанный с этим документом
		COLEDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new COLECntrItem(pDoc);
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
void COLEView::OnCancelEditCntr()
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
void COLEView::OnSetFocus(CWnd* pOldWnd)
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

void COLEView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void COLEView::OnFilePrint()
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



// диагностика COLEView

#ifdef _DEBUG
void COLEView::AssertValid() const
{
	CView::AssertValid();
}

void COLEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COLEDoc* COLEView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDoc)));
	return (COLEDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений COLEView


void COLEView::SetupTracker(COLECntrItem* pItem, CRectTracker* pTracker)
{
	pTracker->m_rect = pItem->m_rect; // установить размеры трассирующей рамки такими же,
	// как и у внедренного объекта

	// если текущий объект является активным,
	// трассирующую рамку нарисовать с маркерами внутри
	if (pItem == m_pSelection)
		pTracker->m_nStyle |= CRectTracker::resizeInside;
	
	// если текущий объект является связанным
	// трассирующую рамку нарисовать точечной линией
	if (pItem->GetType() == OT_LINK)
		pTracker->m_nStyle |= CRectTracker::dottedLine;
	else 
	// в остальных случаях трассирующую рамку рисовать простой линией
	pTracker->m_nStyle |= CRectTracker::solidLine;

	// если объект открыт в режиме редактирования "в отдельном окне" 
	// трассирующую рамку заштриховать косой штриховкой
	if (pItem->GetItemState() == COleClientItem::openState || 
		pItem->GetItemState() == COleClientItem::activeUIState)
		pTracker->m_nStyle |= CRectTracker::hatchInside;	
}

COLECntrItem* COLEView::HitTest(CPoint point)
{
	COLEDoc* pDoc = GetDocument(); // получаем указатель на документ
	COLECntrItem* pHitItem = NULL; // объявляем указатель на верхний объект в точке щелчка
	
	// перебираем коллекцию внедрённых объектов и определяем, какие из них укладываются
	// в точку щелчка.Последний объект коллекции, попавший в точку щелчка, есть верхний.
	POSITION pos = pDoc->GetStartPosition(); // получить позицию первого объекта в коллекции
	while (pos)
	{
	  //получить указатель на текущий объект коллекции, перейдя к следующему объекту
	  COLECntrItem* pCurrentItem = (COLECntrItem*) pDoc->GetNextClientItem(pos);
	  
	  // если текущий объект попал в точку щелчка, запомнить его
	  if (pCurrentItem->m_rect.PtInRect(point))
		  pHitItem = pCurrentItem;
	  return pHitItem; // вернуть указатель на верхний объект в точке щелчка
	}
}

	void COLEView::SetSelection(COLECntrItem* pItem)
	{
	    // если объект редактируется в режиме "на месте", закрываем его
		if (pItem == NULL || pItem != m_pSelection)
		{
			// получить указатель на активный редактируемый на месте объект
		    COleClientItem* pActive = GetDocument()->GetInPlaceActiveItem(this);
			if (pActive != NULL && pActive != pItem)
				pActive->Close(); // закрыть активный объект	
		}
		Invalidate(); // перерисовать окно
		m_pSelection = pItem; // сделать данный объект текущим
	
	}


void COLEView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// определяем верхний объект в точке щелчка
	COLECntrItem* pHitItem = HitTest(point);
	// делаем его текущим и выделяем
	SetSelection(pHitItem); 
	// если в точке щелчка нет объекта, досрочно выходим
	if (pHitItem == NULL)
		return;
	// рисуем трассирующую вокруг текущего объекта
	CRectTracker tracker;
	SetupTracker(pHitItem, &tracker);
	UpdateWindow();
	if (tracker.Track(this, point)) // если изменяется размер трассирующей рамки
	{
		Invalidate(); // постоянно перерисовывать объект вместе с рамкой
		pHitItem->m_rect=tracker.m_rect; // подгояем размер объекта под размер
		GetDocument()->SetModifiedFlag(); // устанавливаем признак изменения документа
	}
	CView::OnLButtonDown(nFlags, point);
}


BOOL COLEView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// если курсор находится над окном представления, и в окне есть выделенный внедрённый объект
	if (pWnd==this && m_pSelection!=NULL) 
	{
	 CRectTracker tracker; // экземпляр класса трассирующей рамки
	 SetupTracker(m_pSelection, &tracker); // подготавливаем внешний вид трассирующей рамки
	 // если изменение указателя мыши при наведении его на трассирующую рамку
	 // завершилось успешно, досрочно выйти из функции
	 if (tracker.SetCursor(pWnd, nHitTest))
	 {
	   return TRUE;
	 }
	}
	 // в остальных случаях показывать стандартный указатель мыши,
	 // определенный настройками ОС
	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void COLEView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// вызываем код обработчика одиночного щелчка мышью
	OnLButtonDown(nFlags, point);

	// если есть внедрённый объект в точке двойного щелчка
	if (m_pSelection!=NULL)
	{
	  // если в момент двойного щелчка удерживалась клавиша Ctrl
		if (GetKeyState(VK_CONTROL)<0)
			m_pSelection->DoVerb(OLEIVERB_OPEN, this); // выполнить команду "открыть"
        else 
			m_pSelection->DoVerb(OLEIVERB_PRIMARY, this); // выполнить главную команду для объекта
	}
	CView::OnLButtonDblClk(nFlags, point);
}


