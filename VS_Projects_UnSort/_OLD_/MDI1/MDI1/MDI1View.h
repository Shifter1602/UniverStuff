
// MDI1View.h : интерфейс класса CMDI1View
//

#pragma once


class CMDI1View : public CView
{
protected: // создать только из сериализации
	CMDI1View();
	DECLARE_DYNCREATE(CMDI1View)

// Атрибуты
public:
	CMDI1Doc* GetDocument() const;

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
	virtual ~CMDI1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в MDI1View.cpp
inline CMDI1Doc* CMDI1View::GetDocument() const
   { return reinterpret_cast<CMDI1Doc*>(m_pDocument); }
#endif

