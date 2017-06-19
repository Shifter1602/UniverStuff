
// MDI_testView.h : интерфейс класса CMDI_testView
//

#pragma once


class CMDI_testView : public CView
{
protected: // создать только из сериализации
	CMDI_testView();
	DECLARE_DYNCREATE(CMDI_testView)

// Атрибуты
public:
	CMDI_testDoc* GetDocument() const;

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
	virtual ~CMDI_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в MDI_testView.cpp
inline CMDI_testDoc* CMDI_testView::GetDocument() const
   { return reinterpret_cast<CMDI_testDoc*>(m_pDocument); }
#endif

