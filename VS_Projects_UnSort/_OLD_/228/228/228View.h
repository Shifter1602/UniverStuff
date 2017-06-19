
// 228View.h : ��������� ������ CMy228View
//

#pragma once

class CMy228CntrItem;

class CMy228View : public CView
{
protected: // ������� ������ �� ������������
	CMy228View();
	DECLARE_DYNCREATE(CMy228View)

// ��������
public:
	CMy228Doc* GetDocument() const;
	// m_pSelection ����������� ���������� ������� � ������� CMy228CntrItem.
	// ��� ������ ����������, ����� ����������-���� �� ���������� ���
	//  ������������� ���������� �������, �������� � ������ ��������� �� ������� �������� ���
	//  ��������� ��������, ������� �� �������� ��������� CMy228CntrItem. ������ ������ ���������
	//  ��������������� � ����� ������ ����������

	// TODO: �������� ������ ������ ��������� � ����� ����������
	CMy228CntrItem* m_pSelection;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// ��������� ����������

// ����������
public:
	virtual ~CMy228View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � 228View.cpp
inline CMy228Doc* CMy228View::GetDocument() const
   { return reinterpret_cast<CMy228Doc*>(m_pDocument); }
#endif

