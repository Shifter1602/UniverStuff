
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
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_CLEAR, &COLEView::OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, &COLEView::OnUpdateEditClear)
END_MESSAGE_MAP()

// создание/уничтожение COLEView

COLEView::COLEView()
{
	m_pSelection = NULL;
	m_focusrectangledrawn = NULL;
	// TODO: добавьте код создания

}

// заполнить структуру формата буфера обмена произвольными данными
CLIPFORMAT COLEView::m_cfObjectDescriptorFormat = (CLIPFORMAT)::RegisterClipboardFormat("Object Descriptor");

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
	if (!pDC)
		return;

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

	// если нажатие ЛК мыши произведено внутри объекта
    if (tracker.HitTest(point)==CRectTracker::hitMiddle)
	{
		CRect rect = pHitItem->m_rect; // запоминаем размеры перетаскиваемого объекта
		CClientDC dc(this); // объявляем контекст класса представления
		OnPrepareDC(&dc); // подготавливаем контекст представления к преобразованию координат
	    dc.LPtoDP(&rect); // выполнить преобразование координат прямоугольника из логических единиц в физические
		rect.NormalizeRect(); // нормализация координат

		// запоминаем отступ положения указателя мыши от левого верхнего угла внедренного объекта
		CPoint newpoint = point - rect.TopLeft();

		// выполнить перетаскивание и запомнить эффект бросания
		DROPEFFECT dropeffect = pHitItem->DoDragDrop(rect, newpoint);
		if (dropeffect == DROPEFFECT_MOVE) // если выполняется перемещение
		{
		  Invalidate(); // перерисовать представление
		  if (pHitItem == m_pSelection) // если перетаскиваемый объект является текущим
			  m_pSelection = NULL;
		  pHitItem->Delete(); // удалить внедренный объект в точке щелчка
		}
	}
	else 
	{
    if (tracker.Track(this, point)) // если изменяется размер трассирующей рамки
	{
		Invalidate(); // постоянно перерисовывать объект вместе с рамкой
		pHitItem->m_rect=tracker.m_rect; // подгояем размер объекта под размер
		GetDocument()->SetModifiedFlag(); // устанавливаем признак изменения документа
	}
	CView::OnLButtonDown(nFlags, point);
}
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


int COLEView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	if (m_droptarget.Register(this)) // если регистрация класса представления в качестве адресата перетаскивания закончилась успешно
    return 0; // ошибок нет
	else return -1; // вернуть код ошибки

}


DROPEFFECT COLEView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	// TODO: добавьте специализированный код или вызов базового класса
	
	ASSERT(!m_focusrectangledrawn); // отладочный макрос, проверяющий, не пустая ли переменная 
	return CView::OnDragEnter(pDataObject, dwKeyState, point);

    // выполняем проверку допустимости перетаскивания объекта над окном данного представления
	m_OKtoDrop = FALSE; // полагаем, что бросать нельзя
	if (!COleClientItem::CanCreateFromData(pDataObject)) // если бросать нельзя
		return DROPEFFECT_NONE;
	m_OKtoDrop = TRUE;
	// с помощью вызова функции GetGlobalData устанавливаются значения dragsize и dragoffset
	HGLOBAL hObjectDescriptor = pDataObject->GetGlobalData(m_cfObjectDescriptorFormat); /*получить глобальный дескриптор объекта*/
	if (hObjectDescriptor) // если дескриптор был получен
	{
		LPOBJECTDESCRIPTOR pObjectDescriptor = (LPOBJECTDESCRIPTOR) GlobalLock(hObjectDescriptor);
		ASSERT(pObjectDescriptor); // проверяем, все ли в  порядке

		// выполняем преобразование координат
		m_dragsize.cx = (int) pObjectDescriptor->sizel.cx;
		m_dragsize.cy = (int) pObjectDescriptor->sizel.cy;
		m_dragoffset.cx = (int) pObjectDescriptor->pointl.x;
		m_dragoffset.cy = (int) pObjectDescriptor->pointl.y;
		// разблокируем и очистим память
		GlobalUnlock(hObjectDescriptor);
		GlobalFree(hObjectDescriptor);
	}
	else
	{
      // присваиваем пустые размеры
	  m_dragsize = CSize(0,0);
	  m_dragoffset = CSize(0,0);
	}



	// преобразование относительно координат пикселей
	CClientDC dc(NULL); // объявляем контекст абстрактного устройства
	dc.HIMETRICtoDP(&m_dragsize);
	dc.HIMETRICtoDP(&m_dragoffset);


	// передача управления перетаскиванием функции OnDragOver
	return OnDragOver(pDataObject, dwKeyState, point);
}


DROPEFFECT COLEView::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	// TODO: добавьте специализированный код или вызов базового класса
	
	// выход, если бросание объекта невозможно
	if (!m_OKtoDrop) return DROPEFFECT_NONE;

	// определение по нажатым клавишам эффекта бросания
	DROPEFFECT dropeffect = DROPEFFECT_NONE; // локальная переменная для эффекта бросания
	if ((dwKeyState & (MK_CONTROL | MK_SHIFT))==(MK_CONTROL|MK_SHIFT))
		// Ctrl+Shift - выполнить связывание
		dropeffect = DROPEFFECT_LINK;

	else if ((dwKeyState & MK_CONTROL)==(MK_CONTROL))
		// Ctrl - выполнить копирование
		dropeffect = DROPEFFECT_COPY;

	else if
		 ((dwKeyState & MK_ALT)==(MK_ALT))
		// Alt - выполнить пересылку 
		dropeffect = DROPEFFECT_MOVE;

		else // во всех остальных случаях
			dropeffect = DROPEFFECT_MOVE;


	// рисование фокусирующей рамки

		point -= m_dragoffset;
	if (point == m_dragpoint) 
	   return dropeffect;
	CClientDC dc(this); // объявляем контекст представления
	// рисуем или стираем рамку
	if (m_focusrectangledrawn)
	{
		dc.DrawFocusRect(CRect(m_dragpoint, m_dragsize));
		m_focusrectangledrawn = FALSE;
	}

	if(dropeffect != DROPEFFECT_NONE) 
	{
	   dc.DrawFocusRect(CRect(point, m_dragsize)); // рисуем фокусирующую рамку в новом месте
	   m_dragpoint = point; // запоминаем значение указателя мыши для следующего рисования
	   m_focusrectangledrawn = TRUE;//
	}
	return dropeffect;


	return CView::OnDragOver(pDataObject, dwKeyState, point);
}


void COLEView::OnDragLeave()
{
	// TODO: добавьте специализированный код или вызов базового класса

	CClientDC dc(this);
	if (m_focusrectangledrawn)
	{   
		// стереть её, нарисовав на том же месте
		dc.DrawFocusRect(CRect(m_dragpoint, m_dragsize));
		m_focusrectangledrawn = FALSE;
	}

	CView::OnDragLeave();
}


BOOL COLEView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point)
{
	// TODO: добавьте специализированный код или вызов базового класса
	ASSERT_VALID(this);
	// удаление фокусирующей рамки
	CClientDC dc(this);	
	if (m_focusrectangledrawn)
	{   
		// стереть её, нарисовав на том же месте
		dc.DrawFocusRect(CRect(m_dragpoint, m_dragsize));
		m_focusrectangledrawn = FALSE;
	}


	// вставка внедрённого объекта
	COLEDoc* pDoc = GetDocument();
	COLECntrItem* pNewItem = new COLECntrItem(pDoc); // получаем указатель на внедренный объект
    ASSERT_VALID(pNewItem);
	if (dropEffect & DROPEFFECT_LINK) // если эффект бросания со связью
		pNewItem->CreateLinkFromData(pDataObject);
	else 
		pNewItem->CreateFromData(pDataObject);
	  ASSERT_VALID(pNewItem);


	// определение размеров объекта и установка его текущим, т.е. выделенным
	  CSize size;
	  pNewItem->GetExtent(&size, pNewItem->GetDrawAspect()); // получить размеры объекта
	  dc.HIMETRICtoDP(&size); // преобразование координат из логических в пиксели
	  point-=m_dragoffset; // смещаем координаты верхнего левого угла объекта
	  pNewItem->m_rect=CRect(point, size); // устанавливаем габариты внедряемого объекта
	  m_pSelection = pNewItem; // устанавливаем новый внедрённый объект текущим

	// обновление представления и установка флажка модификации документа
	  pDoc->SetModifiedFlag();
	  pDoc->UpdateAllViews(NULL);
	  return TRUE;
	  
	  
}


void COLEView::OnEditClear()
{
	// TODO: добавьте свой код обработчика команд
	if (m_pSelection) // // если имеется в окне представления выделенный объект                                   
	{
	  m_pSelection->Delete(); // удалить объект
	  m_pSelection = NULL;
	  GetDocument()->SetModifiedFlag(); // установить флажок изменения документа
	  GetDocument()->UpdateAllViews(NULL); // обновить все представления данного документа
	
	}
}


void COLEView::OnUpdateEditClear(CCmdUI *pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->Enable(m_pSelection!=NULL); // если имеется в окне представления выделенный объект,
	                                    // сделать эту команду доступной, и наоборот
}
