
// browserView.h : интерфейс класса CbrowserView
//

#pragma once


class CbrowserView : public CHtmlView
{
protected: // создать только из сериализации
	CbrowserView();
	DECLARE_DYNCREATE(CbrowserView)

// Атрибуты
public:
	CbrowserDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CbrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGobutton();
};

#ifndef _DEBUG  // отладочная версия в browserView.cpp
inline CbrowserDoc* CbrowserView::GetDocument() const
   { return reinterpret_cast<CbrowserDoc*>(m_pDocument); }
#endif

