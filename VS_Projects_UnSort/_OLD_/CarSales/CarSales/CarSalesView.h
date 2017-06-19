
// CarSalesView.h : интерфейс класса CCarSalesView
//

#pragma once

class CCarSalesSet;

class CCarSalesView : public COleDBRecordView
{
protected: // создать только из сериализации
	CCarSalesView();
	DECLARE_DYNCREATE(CCarSalesView)

public:
	enum{ IDD = IDD_CARSALES_FORM };
	CCarSalesSet* m_pSet;

// Атрибуты
public:
	CCarSalesDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual CRowset<>* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CCarSalesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordEdit();
	afx_msg void OnRecordDelete();
};

#ifndef _DEBUG  // отладочная версия в CarSalesView.cpp
inline CCarSalesDoc* CCarSalesView::GetDocument() const
   { return reinterpret_cast<CCarSalesDoc*>(m_pDocument); }
#endif

