// ���� �������� ��� MFC Samples ������������� ���������������� ����������������� ���������� Fluent �� ������ MFC � Microsoft Office
// ("Fluent UI") � ��������������� ������������� ��� ���������� �������� � �������� ���������� �
// ����������� �� ������ Microsoft Foundation Classes � ��������� ����������� ������������,
// ���������� � ����������� ����������� ���������� MFC C++. 
// ������� ������������� ���������� �� �����������, ������������� ��� ��������������� Fluent UI �������� ��������. 
// ��� ��������� �������������� �������� � ����� ������������ ��������� Fluent UI �������� ���-����
// http://msdn.microsoft.com/officeui.
//
// (C) ���������� ���������� (Microsoft Corp.)
// ��� ����� ��������.

// WordView.h : ��������� ������ CWordView
//

#pragma once

class CWordCntrItem;

class CWordView : public CRichEditView
{
protected: // ������� ������ �� ������������
	CWordView();
	DECLARE_DYNCREATE(CWordView)

// ��������
public:
	CWordDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// ����������
public:
	virtual ~CWordView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � WordView.cpp
inline CWordDoc* CWordView::GetDocument() const
   { return reinterpret_cast<CWordDoc*>(m_pDocument); }
#endif

