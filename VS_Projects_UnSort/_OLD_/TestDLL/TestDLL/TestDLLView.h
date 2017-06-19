
// TestDLLView.h : ��������� ������ CTestDLLView
//

#pragma once


class CTestDLLView : public CView
{
protected: // ������� ������ �� ������������
	CTestDLLView();
	DECLARE_DYNCREATE(CTestDLLView)

// ��������
public:
	CTestDLLDoc* GetDocument() const;

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
	virtual ~CTestDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ���������� ������ � TestDLLView.cpp
inline CTestDLLDoc* CTestDLLView::GetDocument() const
   { return reinterpret_cast<CTestDLLDoc*>(m_pDocument); }
#endif

