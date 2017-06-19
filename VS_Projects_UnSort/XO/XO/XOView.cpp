
// XOView.cpp : implementation of the CXOView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "XO.h"
#include "GameForm.h"
#endif

#include "XODoc.h"
#include "XOView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CXOView

IMPLEMENT_DYNCREATE(CXOView, CView)

BEGIN_MESSAGE_MAP(CXOView, CView)
	ON_COMMAND(ID_START, &CXOView::OnStart)
END_MESSAGE_MAP()

// CXOView construction/destruction

CXOView::CXOView()
{
	// TODO: add construction code here

}

CXOView::~CXOView()
{
}

BOOL CXOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CXOView drawing

void CXOView::OnDraw(CDC* pDC)
{
	CXODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CXOView diagnostics

#ifdef _DEBUG
void CXOView::AssertValid() const
{
	CView::AssertValid();
}

void CXOView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXODoc* CXOView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXODoc)));
	return (CXODoc*)m_pDocument;
}
#endif //_DEBUG


// CXOView message handlers


void CXOView::OnStart()
	{
	CClientDC dc(this);
	GameForm f;
	MessageBox("ggwp");
	f.DoModal();
	Invalidate(1);
	// TODO: Add your command handler code here
	}
