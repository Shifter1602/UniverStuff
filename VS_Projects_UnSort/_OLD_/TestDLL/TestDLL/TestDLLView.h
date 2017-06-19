
// TestDLLView.h : интерфейс класса CTestDLLView
//

#pragma once


class CTestDLLView : public CView
{
protected: // создать только из сериализации
	CTestDLLView();
	DECLARE_DYNCREATE(CTestDLLView)

// Атрибуты
public:
	CTestDLLDoc* GetDocument() const;

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
	virtual ~CTestDLLView();
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

#ifndef _DEBUG  // отладочная версия в TestDLLView.cpp
inline CTestDLLDoc* CTestDLLView::GetDocument() const
   { return reinterpret_cast<CTestDLLDoc*>(m_pDocument); }
#endif

