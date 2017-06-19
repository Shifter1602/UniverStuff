
// DialogTestView.h : interface of the CDialogTestView class
//

#pragma once


class CDialogTestView : public CView
{
protected: // create from serialization only
	CDialogTestView();
	DECLARE_DYNCREATE(CDialogTestView)

// Attributes
public:
	CDialogTestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CDialogTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	};

#ifndef _DEBUG  // debug version in DialogTestView.cpp
inline CDialogTestDoc* CDialogTestView::GetDocument() const
   { return reinterpret_cast<CDialogTestDoc*>(m_pDocument); }
#endif

