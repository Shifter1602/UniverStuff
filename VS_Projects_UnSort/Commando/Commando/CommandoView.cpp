
// CommandoView.cpp : implementation of the CCommandoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Commando.h"
#include "RectDiag.h"
#endif

#include "CommandoDoc.h"
#include "CommandoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandoView

IMPLEMENT_DYNCREATE(CCommandoView, CView)

BEGIN_MESSAGE_MAP(CCommandoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_INSERTSHAPE_RECT, &CCommandoView::OnInsertshapeRect)
END_MESSAGE_MAP()

// CCommandoView construction/destruction

CCommandoView::CCommandoView()
{
	// TODO: add construction code here

}

CCommandoView::~CCommandoView()
{
}

BOOL CCommandoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCommandoView drawing

void CCommandoView::OnDraw(CDC* pDC)
{
	CCommandoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here


}


// CCommandoView printing

BOOL CCommandoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCommandoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCommandoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCommandoView diagnostics

#ifdef _DEBUG
void CCommandoView::AssertValid() const
{
	CView::AssertValid();
}

void CCommandoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCommandoDoc* CCommandoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommandoDoc)));
	return (CCommandoDoc*)m_pDocument;
}
#endif //_DEBUG



void CCommandoView::OnInsertshapeRect()
	{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	//dc.Rectangle(100,100,500,500);
	RectDiag rd;
	rd.DoModal();

	}
