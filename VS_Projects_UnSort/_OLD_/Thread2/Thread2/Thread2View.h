
// Thread2View.h : интерфейс класса CThread2View
//

#pragma once


class CThread2View : public CView
{
protected: // создать только из сериализации
	CThread2View();
	DECLARE_DYNCREATE(CThread2View)

// Атрибуты
public:
	CThread2Doc* GetDocument() const;

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
	virtual ~CThread2View();
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
	CWinThread* m_myThread;
};

#ifndef _DEBUG  // отладочная версия в Thread2View.cpp
inline CThread2Doc* CThread2View::GetDocument() const
   { return reinterpret_cast<CThread2Doc*>(m_pDocument); }
#endif

