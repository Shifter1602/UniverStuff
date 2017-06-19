
// Aplication2View.h : ��������� ������ CAplication2View
//

#pragma once


class CAplication2View : public CView
{
protected: // ������� ������ �� ������������
	CAplication2View();
	DECLARE_DYNCREATE(CAplication2View)

// ��������
public:
	CAplication2Doc* GetDocument() const;

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
	virtual ~CAplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � Aplication2View.cpp
inline CAplication2Doc* CAplication2View::GetDocument() const
   { return reinterpret_cast<CAplication2Doc*>(m_pDocument); }
#endif

