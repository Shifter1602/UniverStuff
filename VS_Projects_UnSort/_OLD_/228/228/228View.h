
// 228View.h : интерфейс класса CMy228View
//

#pragma once

class CMy228CntrItem;

class CMy228View : public CView
{
protected: // создать только из сериализации
	CMy228View();
	DECLARE_DYNCREATE(CMy228View)

// Атрибуты
public:
	CMy228Doc* GetDocument() const;
	// m_pSelection захватывает выделенную область в текущий CMy228CntrItem.
	// Для многих приложений, такая переменная-член не достаточна для
	//  представления выделенной области, например в случае выделения не смежных областей или
	//  выделения объектов, которые не являются объектами CMy228CntrItem. Данный способ выделения
	//  предоставляется с целью помощи начинающим

	// TODO: замените данный способ выделения в вашем приложении
	CMy228CntrItem* m_pSelection;

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
	virtual ~CMy228View();
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
};

#ifndef _DEBUG  // отладочная версия в 228View.cpp
inline CMy228Doc* CMy228View::GetDocument() const
   { return reinterpret_cast<CMy228Doc*>(m_pDocument); }
#endif

