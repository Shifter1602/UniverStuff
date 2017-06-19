
// Thread1View.h : ��������� ������ CThread1View
//

#pragma once


class CThread1View : public CView
{
protected: // ������� ������ �� ������������
	CThread1View();
	DECLARE_DYNCREATE(CThread1View)

// ��������
public:
	CThread1Doc* GetDocument() const;

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
	virtual ~CThread1View();
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

#ifndef _DEBUG  // ���������� ������ � Thread1View.cpp
inline CThread1Doc* CThread1View::GetDocument() const
   { return reinterpret_cast<CThread1Doc*>(m_pDocument); }
#endif

