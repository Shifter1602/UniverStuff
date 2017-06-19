
// BrowserView.h : ��������� ������ CBrowserView
//

#pragma once


class CBrowserView : public CHtmlView
{
protected: // ������� ������ �� ������������
	CBrowserView();
	DECLARE_DYNCREATE(CBrowserView)

// ��������
public:
	CBrowserDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������

// ����������
public:
	virtual ~CBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton();
};

#ifndef _DEBUG  // ���������� ������ � BrowserView.cpp
inline CBrowserDoc* CBrowserView::GetDocument() const
   { return reinterpret_cast<CBrowserDoc*>(m_pDocument); }
#endif

