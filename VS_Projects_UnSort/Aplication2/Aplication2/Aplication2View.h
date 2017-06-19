
// Aplication2View.h : интерфейс класса CAplication2View
//

#pragma once


class CAplication2View : public CView
{
protected: // создать только из сериализации
	CAplication2View();
	DECLARE_DYNCREATE(CAplication2View)

// Атрибуты
public:
	CAplication2Doc* GetDocument() const;

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
	virtual ~CAplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в Aplication2View.cpp
inline CAplication2Doc* CAplication2View::GetDocument() const
   { return reinterpret_cast<CAplication2Doc*>(m_pDocument); }
#endif

