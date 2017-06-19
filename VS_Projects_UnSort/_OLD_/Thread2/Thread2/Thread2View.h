
// Thread2View.h : ��������� ������ CThread2View
//

#pragma once


class CThread2View : public CView
{
protected: // ������� ������ �� ������������
	CThread2View();
	DECLARE_DYNCREATE(CThread2View)

// ��������
public:
	CThread2Doc* GetDocument() const;

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
	virtual ~CThread2View();
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
	CWinThread* m_myThread;
};

#ifndef _DEBUG  // ���������� ������ � Thread2View.cpp
inline CThread2Doc* CThread2View::GetDocument() const
   { return reinterpret_cast<CThread2Doc*>(m_pDocument); }
#endif

