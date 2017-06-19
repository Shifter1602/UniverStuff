
// OLEView.h : ��������� ������ COLEView
//

#pragma once

class COLECntrItem;

class COLEView : public CView
{
protected: // ������� ������ �� ������������
	COLEView();
	DECLARE_DYNCREATE(COLEView)

// ��������
public:
	COLEDoc* GetDocument() const;
	// m_pSelection ����������� ���������� ������� � ������� COLECntrItem.
	// ��� ������ ����������, ����� ����������-���� �� ���������� ���
	//  ������������� ���������� �������, �������� � ������ ��������� �� ������� �������� ���
	//  ��������� ��������, ������� �� �������� ��������� COLECntrItem. ������ ������ ���������
	//  ��������������� � ����� ������ ����������

	// TODO: �������� ������ ������ ��������� � ����� ����������
	COLECntrItem* m_pSelection;

// ��������
public:
	void SetupTracker(COLECntrItem* pItem, CRectTracker* pTracker);
	COLECntrItem* HitTest(CPoint point); 
	void SetSelection(COLECntrItem* pItem);
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
	virtual ~COLEView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ���������� ������ � OLEView.cpp
inline COLEDoc* COLEView::GetDocument() const
   { return reinterpret_cast<COLEDoc*>(m_pDocument); }
#endif

