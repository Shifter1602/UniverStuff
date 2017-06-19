
// CarSalesView.h : ��������� ������ CCarSalesView
//

#pragma once

class CCarSalesSet;

class CCarSalesView : public COleDBRecordView
{
protected: // ������� ������ �� ������������
	CCarSalesView();
	DECLARE_DYNCREATE(CCarSalesView)

public:
	enum{ IDD = IDD_CARSALES_FORM };
	CCarSalesSet* m_pSet;

// ��������
public:
	CCarSalesDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual CRowset<>* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CCarSalesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordEdit();
	afx_msg void OnRecordDelete();
};

#ifndef _DEBUG  // ���������� ������ � CarSalesView.cpp
inline CCarSalesDoc* CCarSalesView::GetDocument() const
   { return reinterpret_cast<CCarSalesDoc*>(m_pDocument); }
#endif

