
// CommandorView.cpp : implementation of the CCommandorView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Commandor.h"
#endif

#include "CommandorDoc.h"
#include "CommandorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandorView

IMPLEMENT_DYNCREATE(CCommandorView, CView)

BEGIN_MESSAGE_MAP(CCommandorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCommandorView construction/destruction

CCommandorView::CCommandorView()
{
	// TODO: add construction code here

}

CCommandorView::~CCommandorView()
{
}

BOOL CCommandorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCommandorView drawing

void CCommandorView::OnDraw(CDC* pDC)
{
	CCommandorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(0,0,500,500);
	// TODO: add draw code for native data here
}


// CCommandorView printing

BOOL CCommandorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCommandorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCommandorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCommandorView diagnostics

#ifdef _DEBUG
void CCommandorView::AssertValid() const
{
	CView::AssertValid();
}

void CCommandorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCommandorDoc* CCommandorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommandorDoc)));
	return (CCommandorDoc*)m_pDocument;
}
#endif //_DEBUG


// CCommandorView message handlers
