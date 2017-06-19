
// BrowserView.h : интерфейс класса CBrowserView
//

#pragma once


class CBrowserView : public CHtmlView
{
protected: // создать только из сериализации
	CBrowserView();
	DECLARE_DYNCREATE(CBrowserView)

// Атрибуты
public:
	CBrowserDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton();
};

#ifndef _DEBUG  // отладочная версия в BrowserView.cpp
inline CBrowserDoc* CBrowserView::GetDocument() const
   { return reinterpret_cast<CBrowserDoc*>(m_pDocument); }
#endif

