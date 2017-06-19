
// MDI1View.h : ��������� ������ CMDI1View
//

#pragma once


class CMDI1View : public CView
{
protected: // ������� ������ �� ������������
	CMDI1View();
	DECLARE_DYNCREATE(CMDI1View)

// ��������
public:
	CMDI1Doc* GetDocument() const;

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
	virtual ~CMDI1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � MDI1View.cpp
inline CMDI1Doc* CMDI1View::GetDocument() const
   { return reinterpret_cast<CMDI1Doc*>(m_pDocument); }
#endif

