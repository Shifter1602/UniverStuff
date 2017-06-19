
// PotokView.h : интерфейс класса CPotokView
//

#pragma once


class CPotokView : public CView
{
protected: // создать только из сериализации
	CPotokView();
	DECLARE_DYNCREATE(CPotokView)

// Атрибуты
public:
	CPotokDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CPotokView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // отладочная версия в PotokView.cpp
inline CPotokDoc* CPotokView::GetDocument() const
   { return reinterpret_cast<CPotokDoc*>(m_pDocument); }
#endif

