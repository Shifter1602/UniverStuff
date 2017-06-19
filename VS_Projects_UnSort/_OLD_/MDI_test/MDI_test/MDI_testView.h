
// MDI_testView.h : ��������� ������ CMDI_testView
//

#pragma once


class CMDI_testView : public CView
{
protected: // ������� ������ �� ������������
	CMDI_testView();
	DECLARE_DYNCREATE(CMDI_testView)

// ��������
public:
	CMDI_testDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CMDI_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � MDI_testView.cpp
inline CMDI_testDoc* CMDI_testView::GetDocument() const
   { return reinterpret_cast<CMDI_testDoc*>(m_pDocument); }
#endif

