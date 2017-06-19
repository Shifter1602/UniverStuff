
// OLEView.h : интерфейс класса COLEView
//

#pragma once

class COLECntrItem;


class COLEView : public CView
{
	static CLIPFORMAT m_cfObjectDescriptorFormat;//Экз. структуры формата буфера обмена
protected: // создать только из сериализации
	COLEView();
	DECLARE_DYNCREATE(COLEView)

// Атрибуты
public:
	COLEDoc* GetDocument() const;
	// m_pSelection захватывает выделенную область в текущий COLECntrItem.
	// Для многих приложений, такая переменная-член не достаточна для
	//  представления выделенной области, например в случае выделения не смежных областей или
	//  выделения объектов, которые не являются объектами COLECntrItem. Данный способ выделения
	//  предоставляется с целью помощи начинающим

	// TODO: замените данный способ выделения в вашем приложении
	COLECntrItem* m_pSelection;
	COleDropTarget m_droptarget;//Объект. перем. для регистрац. окна представл. в кач-ве адресата перетаск.
	CPoint m_dragpoint;//точка указ. мыши
	CSize m_dragsize;//габариты перетаск. об-та
	CSize m_dragoffset;//отступ указ. мыши от левого верх. угла об-та
	BOOL m_OktoDrop;//перем. запин. можно ли бросать об-т в данном месте
	BOOL m_FocusRectangleDrawn;//перем. запомин. была ли нарис. фокус. рамка

// Операции
public:
	void SetupTracker(COLECntrItem* pItem, CRectTracker* pTracker);
	COLECntrItem* HitTest(CPoint point); 
	void SetSelection(COLECntrItem* pItem);
// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Поддержка контейнера

// Реализация
public:
	virtual ~COLEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual void OnDragLeave();
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // отладочная версия в OLEView.cpp
inline COLEDoc* COLEView::GetDocument() const
   { return reinterpret_cast<COLEDoc*>(m_pDocument); }
#endif

