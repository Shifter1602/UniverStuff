
// CommandoView.h : interface of the CCommandoView class
//

#pragma once


class CCommandoView : public CView
{
protected: // create from serialization only
	CCommandoView();
	DECLARE_DYNCREATE(CCommandoView)

// Attributes
public:
	CCommandoDoc* GetDocument() const;

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
	virtual ~CCommandoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnInsertshapeRect();
	};

#ifndef _DEBUG  // debug version in CommandoView.cpp
inline CCommandoDoc* CCommandoView::GetDocument() const
   { return reinterpret_cast<CCommandoDoc*>(m_pDocument); }
#endif

