
// CommandorView.h : interface of the CCommandorView class
//

#pragma once


class CCommandorView : public CView
{
protected: // create from serialization only
	CCommandorView();
	DECLARE_DYNCREATE(CCommandorView)

// Attributes
public:
	CCommandorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCommandorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CommandorView.cpp
inline CCommandorDoc* CCommandorView::GetDocument() const
   { return reinterpret_cast<CCommandorDoc*>(m_pDocument); }
#endif

