
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
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_OLE_INSERT_NEW, &COLEView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &COLEView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &COLEView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
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
	m_FocusRectangleDrawn = NULL;
	// TODO: добавьте код создания

}
//заполнить структура формата буфера обмена произвольными данными
CLIPFORMAT COLEView::m_cfObjectDescriptorFormat =
	(CLIPFORMAT)::RegisterClipboardFormat("Object Descriptor");

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
	
	/*if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);
		
		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		*/
		//Нарисовать внедренный объект, вписав его в прямоугольник m_rect
	POSITION pos = pDoc->GetStartPosition();
	while(pos)
	{
		COLECntrItem* pCurrentItem = 
			(COLECntrItem*) pDoc->GetNextClientItem(pos);
		pCurrentItem->Draw(pDC,pCurrentItem->m_rect);//нарисовать слующий объект в коллекции
	
		//Если объект является выделенным, рисуем трассирующую рамку
		if (pCurrentItem == m_pSelection)
		{
			CRectTracker tracker;//объявляем экземпляр трассирующей рамки
			SetupTracker(m_pSelection, &tracker);//вызываем нашу функцию для подготовки вида трассирующей рамки
			tracker.Draw(pDC); //нарисовать трассирующую рамку
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

void COLEView::SetupTracker(COLECntrItem* pItem, CRectTracker* pTracker)
{
	// установить размеры трассирующей рамки такими же, 
	//как и у внедренного объекта
	pTracker->m_rect = pItem->m_rect; 
	
	//если текущий объект является активным
	//трассирующую рамку нарисовать с маркерами внутри
	if(pItem == m_pSelection)
		pTracker->m_nStyle |= CRectTracker::resizeInside;

	//если текущий объект является связанным,
	//трассирующую рамку нарисовать точечной линией
	if(pItem->GetType() == OT_LINK)
		pTracker->m_nStyle |= CRectTracker::dottedLine;
	//в остальных случаях 
	//трассирующую рамку нарисовать сплошной линией
	else
		pTracker->m_nStyle |= CRectTracker::solidLine;

	//если объект открыт в режиме редактирования "в отдельном окне"
	//трассирующую рамку заштриховать косой штриховкой
	if(pItem->GetItemState()==COleClientItem::openState ||
		pItem->GetItemState()==COleClientItem::activeUIState)
		pTracker->m_nStyle |= CRectTracker::hatchInside;
	}

COLECntrItem* COLEView::HitTest(CPoint point)
{
	COLEDoc* pDoc = GetDocument(); // получаем указатель на документ
	COLECntrItem* pHitItem = NULL; // Объявлем указатель на "верхний" объект в точке щелчка

	//перебираем коллекцию внедренных объектов и определяем, какие из них
	//укладываются в точку щелчка. Последний объект коллекции, попавший в
	//точку щелчка является "верхним"
	POSITION pos = pDoc->GetStartPosition();//получить позицию первого объекта в коллекции
	while(pos)
	{
		//получить указатель на текущий объект коллекции, перейдя к следующему объекту
		COLECntrItem* pCurrentItem = 
			(COLECntrItem*) pDoc->GetNextClientItem(pos);
		//если текущий объект попал в точку щелчка, запомнить его
		if(pCurrentItem->m_rect.PtInRect(point))
			pHitItem=pCurrentItem;
	}
	return pHitItem; // вернуть указатель на "верхний" объект в точке щелчка
}


void COLEView::SetSelection(COLECntrItem* pItem)
{
	//если объект редактируется в режиме "на месте", закрываем его
	if(pItem == NULL || pItem != m_pSelection)
	{
		//получить указатель на активный редактируемый на месте объект
		COleClientItem* pActive = GetDocument()->GetInPlaceActiveItem(this);
		if(pActive != NULL && pActive != pItem)
			pActive->Close();//закрыть активный объект
	}
	Invalidate(); //перерисовать окно представления
	m_pSelection = pItem; // сделать данный объект текущим
}

void COLEView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//Определяем верхний объект в точке щелчка
	COLECntrItem* pHitItem = HitTest(point);
	//Делаем его текущим и выделяем
	SetSelection(pHitItem);
	//Если в точке щелчка нет объекта, досрочно выходим
	if(pHitItem == NULL)
		return;
	//Рисуем трассирующую рамку вокруг текущего объекта
	CRectTracker tracker;
	SetupTracker(pHitItem,&tracker);
	UpdateWindow(); //обновить окно
	//Если нажатие ЛКМ произведено внутри об-та
	if(tracker.HitTest(point)==CRectTracker::hitMiddle)
	{
		CRect rect = pHitItem->m_rect;//запоминаем размеры об-та
		CClientDC dc(this);//Объявл. контекст класса представления
		OnPrepareDC(&dc);//Подгот. контекст предст. к преобр. коор-т
		dc.LPtoDP(&rect);//Выполн. преобр. коор-т прямоуг. из логич. в физические
		rect.NormalizeRect();//Нормализация коор-т
		//запомин. отступ полож. указ. мыши от лев.верхн. угла внедр. об-та
		CPoint newpoint = point-rect.TopLeft();
		//Выполн. перетаск. и запомн. эффект бросания
		DROPEFFECT dropeffect = pHitItem->DoDragDrop(rect,newpoint);
		if(dropeffect==DROPEFFECT_MOVE)//Если выполн. перемещ.
		{
			Invalidate();//Перерис. представление
			if(pHitItem==m_pSelection)//Если перетаск.об-т явл-ся текущим
				m_pSelection=NULL;
			pHitItem->Delete();//Удалить внедр.об-т в т-ке щелчка
		}
		else
		{
			if (tracker.Track(this,point))//если изменяется размер трассирующей рамки
			{
				Invalidate();//постоянно перерисовываем объект вместе с рамкой
				pHitItem->m_rect=tracker.m_rect;//подгоняем размер объекта под размер трассирующей рамки
				GetDocument()->SetModifiedFlag();//устанавливаем признак изменения документа
			}
		}

	}
	


}
// обработчики сообщений COLEView


BOOL COLEView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if(pWnd==this && m_pSelection!=NULL)// Если курсор находится над окном представления и в окне есть выделенный внедренный объект
	{
		CRectTracker tracker;//Экземпляр трасс. рамки
		SetupTracker(m_pSelection,&tracker);//подготавливаем внешний вид трассирующей рамки
		//Если изменение указателя мыши при наведении его на трассирующую рамку завершилось успешно,
		//досрочно выйти из функции
		if(tracker.SetCursor(pWnd,nHitTest))
		{
			return TRUE;
		}//в остальных случаях показывать стандартный указатель мыши,
		 //определ. настройками ОС

	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void COLEView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	//Вызываем код обработчика одиночного щелчка мышью
	OnLButtonDown(nFlags,point);
	//Если в точке дв.щелчка есть внедренный объект
	if(m_pSelection!=NULL)
	{
		//Если в момент двойного щелчка удерживалась клавиша Стрл.
		if(GetKeyState(VK_CONTROL)<0)
			m_pSelection->DoVerb(OLEIVERB_OPEN,this);//Выполнить комманду открыть
		else
			m_pSelection->DoVerb(OLEIVERB_PRIMARY,this);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


int COLEView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	if(m_droptarget.Register(this))//Если регистр. класса представ. в кач-ве адресата законч. успешно
		return 0;
	else
		return -1;
}


DROPEFFECT COLEView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	// TODO: добавьте специализированный код или вызов базового класса
	//Отлад. макрос проверяющ. не явл. ли перем. пустой
	ASSERT(!m_FocusRectangleDrawn);
	//Выполн. проверку допустимости перетаск. об-та над окном данного представления
	m_OktoDrop = FALSE;//Для начала полаг. что перетаск. нельзя
	if(COleClientItem::CanCreateFromData(pDataObject))//Если бросать нельзя возвр. DROPEFFECT_NONE
		return DROPEFFECT_NONE;
	//Если попали сюда, то бросать можно, продолж. выполн. ф-ии
	m_OktoDrop = TRUE;
	//С помощ. вызова ф-ии GetGlobalData устанавл. знач. dragsize dragoffset
	HGLOBAL hObjectDescriptor = pDataObject->GetGlobalData(m_cfObjectDescriptorFormat);//получить глоб. дескрит. об-та
	if(hObjectDescriptor)//Если дескриптор был получен
	{
		//блокируем память
		LPOBJECTDESCRIPTOR pObjectDescriptor = (LPOBJECTDESCRIPTOR) GlobalLock(hObjectDescriptor);
		ASSERT(pObjectDescriptor);
		//
		m_dragsize.cx = (int) pObjectDescriptor->sizel.cx;
		m_dragsize.cy = (int) pObjectDescriptor->sizel.cy;
		m_dragoffset.cx = (int) pObjectDescriptor->pointl.x;
		m_dragoffset.cy = (int) pObjectDescriptor->pointl.y;
		//
		GlobalUnlock(pObjectDescriptor);
		GlobalFree(hObjectDescriptor);

	}
	else
	{
		//присв. пустые размеры
		m_dragsize = CSize(0,0);
		m_dragoffset = CSize(0,0);
	}

	//Преобр. относ. коор-т в пиксели
	CClientDC dc(NULL);// Объявл. контекст абстракт. условия
	dc.HIMETRICtoDP(&m_dragsize);
	dc.HIMETRICtoDP(&m_dragoffset);
	//Перед. управл. перетаск. ф-ии OnDragOver
	return OnDragOver(pDataObject,dwKeyState,point);
}


void COLEView::OnDragLeave()
{
	// TODO: добавьте специализированный код или вызов базового класса
	CClientDC dc(this);
	if(m_FocusRectangleDrawn)
	{
		dc.DrawFocusRect(CRect(m_dragpoint,m_dragsize));
		m_FocusRectangleDrawn=FALSE;
	}
	CView::OnDragLeave();
}


DROPEFFECT COLEView::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	// TODO: добавьте специализированный код или вызов базового класса
	//Выход если бросание об-та невозможно

	if(!m_OktoDrop)
		return DROPEFFECT_NONE;
	//Определение по нажатым клавишам эффекта бросания
	DROPEFFECT dropeffect = DROPEFFECT_NONE;//Локал. прем. для эфф.бросания
	if((dwKeyState & (MK_CONTROL|MK_SHIFT))==(MK_CONTROL|MK_SHIFT))
		//Ctrl+Shift - выполнить связывание
		dropeffect = DROPEFFECT_LINK;
	else if((dwKeyState & MK_CONTROL)==MK_CONTROL)
		//Ctrl - выполнить копировние
		dropeffect = DROPEFFECT_COPY; 
	else if((dwKeyState & MK_ALT)==MK_ALT)
		//Alt - пересылка
		dropeffect = DROPEFFECT_MOVE;
	else
		dropeffect = DROPEFFECT_MOVE;
	//Рисование фокус. рамки
	point -=m_dragoffset;
	//Если коорд. лев. угла об-та совпали с коорд. рамки , рамку надо удалить...
	
	if(point == m_dragpoint)
		return dropeffect;
	CClientDC dc(this);//щпрел. контекст
	//рисуем или стираем рамку
	if(m_FocusRectangleDrawn)
	{
		//стереть ее нарисовав на новом месте
		dc.DrawFocusRect(CRect(m_dragpoint,m_dragsize));
		m_FocusRectangleDrawn = FALSE;
	}
	if(dropeffect!=DROPEFFECT_NONE)//Если можно бросать об-т
	{
		//рисуем фокус. рамку вновом месте
		dc.DrawFocusRect(CRect(point,m_dragsize));
		//
		m_dragpoint = point;
		m_FocusRectangleDrawn = TRUE;
	}
	return dropeffect;
	return OnDragOver(pDataObject,dwKeyState,point);
}


BOOL COLEView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point)
{
	// TODO: добавьте специализированный код или вызов базового класса
	ASSERT_VALID(this);
	CClientDC dc(this);
	//улаение фокус рамки
	if(m_FocusRectangleDrawn)
	{
		//стереть ее нарисовав на новом месте
		dc.DrawFocusRect(CRect(point,m_dragoffset));
		m_FocusRectangleDrawn = FALSE;
	}
	//вствака внедр об-та
	COLEDoc* pDoc = GetDocument();//получ указ. на док.
	COLECntrItem* pNewItem = new COLECntrItem(pDoc);//получ указ на внедр об-т
	ASSERT_VALID(pNewItem);
	if(dropEffect & DROPEFFECT_LINK)//Если эфф. бросания со связью
		pNewItem->CreateLinkFromData(pDataObject);
	else
		pNewItem->CreateFromData(pDataObject);
	//опред разм об-та и установка его текущим
	CSize size;
	pNewItem->GetExtent(&size,pNewItem->GetDrawAspect());//получ. разм. об-та
	dc.HIMETRICtoDP(&size);
	point-=m_dragoffset;
	pNewItem->m_rect=CRect(point,size);
	m_pSelection=pNewItem;
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);
	return TRUE;
}


void COLEView::OnEditClear()
{
	// TODO: добавьте свой код обработчика команд
	if(m_pSelection)
	{
		m_pSelection->Delete();
		m_pSelection = NULL;
		GetDocument()->SetModifiedFlag();
		GetDocument()->UpdateAllViews(NULL);
	}
}


void COLEView::OnUpdateEditClear(CCmdUI *pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->Enable(m_pSelection!=NULL);
}
