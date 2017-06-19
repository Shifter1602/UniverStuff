
// OLEView.h : интерфейс класса COLEView
//

#pragma once

class COLECntrItem;

class COLEView : public CView
{
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

// Операции
public:

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
	DECLARE_MESSAGE_MAP()
public:
	void SetupTracker(COLECntrItem* pItem, CRectTracker* pTracker);
	COLECntrItem* HitTest(CPoint point);
	void SetSelection(COLECntrItem* pItem);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	
};

#ifndef _DEBUG  // отладочная версия в OLEView.cpp
inline COLEDoc* COLEView::GetDocument() const
   { return reinterpret_cast<COLEDoc*>(m_pDocument); }
#endif

