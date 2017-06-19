
// CompositionView.cpp : implementation of the CCompositionView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Composition.h"
#endif

#include "CompositionDoc.h"
#include "CompositionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCompositionView

IMPLEMENT_DYNCREATE(CCompositionView, CView)

BEGIN_MESSAGE_MAP(CCompositionView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCompositionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCompositionView construction/destruction

CCompositionView::CCompositionView()
{
	// TODO: add construction code here

}

CCompositionView::~CCompositionView()
{
}

BOOL CCompositionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCompositionView drawing

void CCompositionView::OnDraw(CDC* pDC)
{
	CCompositionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RECT rect;
	rect.bottom=100;rect.top=100;rect.left=100;rect.right=rect.left+100;
	//pDC->Rectangle(0,0,500,500);
	//pDC->Ellipse(250,250,400,400);
	pDC->TextOutW(10,10,rect,(CString)("fcsedffere"));


	// TODO: add draw code for native data here
}


// CCompositionView printing


void CCompositionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCompositionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCompositionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCompositionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCompositionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCompositionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCompositionView diagnostics

#ifdef _DEBUG
void CCompositionView::AssertValid() const
{
	CView::AssertValid();
}

void CCompositionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCompositionDoc* CCompositionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCompositionDoc)));
	return (CCompositionDoc*)m_pDocument;
}
#endif //_DEBUG


// CCompositionView message handlers
