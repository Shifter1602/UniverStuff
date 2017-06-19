
// browserView.h : ��������� ������ CbrowserView
//

#pragma once


class CbrowserView : public CHtmlView
{
protected: // ������� ������ �� ������������
	CbrowserView();
	DECLARE_DYNCREATE(CbrowserView)

// ��������
public:
	CbrowserDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������

// ����������
public:
	virtual ~CbrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGobutton();
};

#ifndef _DEBUG  // ���������� ������ � browserView.cpp
inline CbrowserDoc* CbrowserView::GetDocument() const
   { return reinterpret_cast<CbrowserDoc*>(m_pDocument); }
#endif

