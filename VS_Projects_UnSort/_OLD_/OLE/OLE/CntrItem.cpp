
// CntrItem.cpp : реализация класса COLECntrItem
//

#include "stdafx.h"
#include "OLE.h"

#include "OLEDoc.h"
#include "OLEView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация COLECntrItem

IMPLEMENT_SERIAL(COLECntrItem, COleClientItem, 0)

COLECntrItem::COLECntrItem(COLEDoc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: добавьте код для одноразового вызова конструктора
	m_rect = CRect(10,10,210,210);
}

COLECntrItem::~COLECntrItem()
{
	// TODO: добавьте код очистки
}

void COLECntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// Во время редактирования элемента (либо по месту, либо когда он полностью открыт),
	//  отправляются уведомления OnChange об изменении состояния
	//  этого элемента или визуального изображения его содержимого.

	// TODO: сделайте элемент недопустимым посредством вызова UpdateAllViews
	//  (с указаниями, подходящими для вашего приложения)

	GetDocument()->UpdateAllViews(NULL);
		// обновите ВСЕ представления без указаний
}

BOOL COLECntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// Во время активации по месту COLECntrItem::OnChangeItemPosition
	//  вызывается сервером для изменения положения окна
	//  по месту. Обычно это возникает в случае, когда данные документа
	//  на сервере изменены таким образом, что изменяется его величина, либо в случае
	//  изменения размеров по месту.
	//
	// По умолчанию вызывается базовый класс, который вызывает
	//  COleClientItem::SetItemRects для перемещения элемента
	//  в новое положение.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: обновите имеющийся кэш прямоугольника или величины
	m_rect= rectPos;
	GetDocument()->SetModifiedFlag();
	GetDocument()->UpdateAllViews(NULL);
	return TRUE;
}

BOOL COLECntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}

void COLECntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// Во время активации по месту COLECntrItem::OnGetItemPosition
	//  будет вызван для определения расположения этого элемента. Обычно этот 
	//  прямоугольник определяет текущее положение элемента по отношению к 
	//  представлению, используемому для активации. Чтобы получить это представление, вызовите 
	//  COLECntrItem::GetActiveView.

	// TODO: возвратите правильный прямоугольник (в пикселах) в rPosition

	/*CSize size;
	rPosition.SetRectEmpty();
	if (GetExtent(&size, m_nDrawAspect))
	{
		COLEView* pView = GetActiveView();
		ASSERT_VALID(pView);
		if (!pView)
			return;
		CDC *pDC = pView->GetDC();
		ASSERT(pDC);
		if (!pDC)
			return;
		pDC->HIMETRICtoLP(&size);
		rPosition.SetRect(10, 10, size.cx + 10, size.cy + 10);
	}
	else
		rPosition.SetRect(10, 10, 210, 210);*/
	rPosition=m_rect;
}

void COLECntrItem::OnActivate()
{
    // Разрешить только один элемент активации по месту для одной рамки
    COLEView* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void COLECntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void COLECntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Вызовите сначала базовый класс для чтения данных COleClientItem.
	// Поскольку при этом настраивается положение указателя m_pDocument, возвращенного из
	//  COLECntrItem::GetDocument, рекомендуется сначала вызвать
	//  базовый класс Serialize.
	COleClientItem::Serialize(ar);

	// для хранения или извлечения данных, относящихся к COLECntrItem
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
		ar << m_rect;
	}
	else
	{
		// TODO: добавьте код загрузки
		ar >> m_rect;
	}
}


// диагностика COLECntrItem

#ifdef _DEBUG
void COLECntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void COLECntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

