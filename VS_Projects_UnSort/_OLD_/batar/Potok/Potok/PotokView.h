
// PotokView.h : ��������� ������ CPotokView
//

#pragma once


class CPotokView : public CView
{
protected: // ������� ������ �� ������������
	CPotokView();
	DECLARE_DYNCREATE(CPotokView)

// ��������
public:
	CPotokDoc* GetDocument() const;

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
	virtual ~CPotokView();
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

#ifndef _DEBUG  // ���������� ������ � PotokView.cpp
inline CPotokDoc* CPotokView::GetDocument() const
   { return reinterpret_cast<CPotokDoc*>(m_pDocument); }
#endif

