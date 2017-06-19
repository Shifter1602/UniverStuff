
// MDIView.h : интерфейс класса CMDIView
//

#pragma once


class CMDIView : public CView
{
protected: // создать только из сериализации
	CMDIView();
	DECLARE_DYNCREATE(CMDIView)

// Атрибуты
public:
	CMDIDoc* GetDocument() const;

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
	virtual ~CMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в MDIView.cpp
inline CMDIDoc* CMDIView::GetDocument() const
   { return reinterpret_cast<CMDIDoc*>(m_pDocument); }
#endif

