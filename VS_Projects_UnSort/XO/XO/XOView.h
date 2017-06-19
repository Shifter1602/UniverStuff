
// XOView.h : interface of the CXOView class
//

#pragma once


class CXOView : public CView
{
protected: // create from serialization only
	CXOView();
	DECLARE_DYNCREATE(CXOView)

// Attributes
public:
	CXODoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CXOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStart();
	};

#ifndef _DEBUG  // debug version in XOView.cpp
inline CXODoc* CXOView::GetDocument() const
   { return reinterpret_cast<CXODoc*>(m_pDocument); }
#endif

