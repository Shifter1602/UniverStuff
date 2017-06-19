
// CntrItem.cpp : реализация класса CMy228CntrItem
//

#include "stdafx.h"
#include "228.h"

#include "228Doc.h"
#include "228View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CMy228CntrItem

IMPLEMENT_SERIAL(CMy228CntrItem, COleClientItem, 0)

CMy228CntrItem::CMy228CntrItem(CMy228Doc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: добавьте код для одноразового вызова конструктора
}

CMy228CntrItem::~CMy228CntrItem()
{
	// TODO: добавьте код очистки
}

void CMy228CntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
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

BOOL CMy228CntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// Во время активации по месту CMy228CntrItem::OnChangeItemPosition
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

	return TRUE;
}

BOOL CMy228CntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}

void CMy228CntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// Во время активации по месту CMy228CntrItem::OnGetItemPosition
	//  будет вызван для определения расположения этого элемента. Обычно этот 
	//  прямоугольник определяет текущее положение элемента по отношению к 
	//  представлению, используемому для активации. Чтобы получить это представление, вызовите 
	//  CMy228CntrItem::GetActiveView.

	// TODO: возвратите правильный прямоугольник (в пикселах) в rPosition

	CSize size;
	rPosition.SetRectEmpty();
	if (GetExtent(&size, m_nDrawAspect))
	{
		CMy228View* pView = GetActiveView();
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
		rPosition.SetRect(10, 10, 210, 210);
}

void CMy228CntrItem::OnActivate()
{
    // Разрешить только один элемент активации по месту для одной рамки
    CMy228View* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void CMy228CntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CMy228CntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Вызовите сначала базовый класс для чтения данных COleClientItem.
	// Поскольку при этом настраивается положение указателя m_pDocument, возвращенного из
	//  CMy228CntrItem::GetDocument, рекомендуется сначала вызвать
	//  базовый класс Serialize.
	COleClientItem::Serialize(ar);

	// для хранения или извлечения данных, относящихся к CMy228CntrItem
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}


// диагностика CMy228CntrItem

#ifdef _DEBUG
void CMy228CntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CMy228CntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

