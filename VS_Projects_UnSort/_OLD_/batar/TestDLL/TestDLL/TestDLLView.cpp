
// TestDLLView.cpp : ���������� ������ CTestDLLView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "TestDLL.h"
#endif

#include "TestDLLDoc.h"
#include "TestDLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestDLLView

IMPLEMENT_DYNCREATE(CTestDLLView, CView)

BEGIN_MESSAGE_MAP(CTestDLLView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� CTestDLLView

CTestDLLView::CTestDLLView()
{
	// TODO: �������� ��� ��������

}

CTestDLLView::~CTestDLLView()
{
}

BOOL CTestDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CTestDLLView

void CTestDLLView::OnDraw(CDC* /*pDC*/)
{
	CTestDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CTestDLLView

BOOL CTestDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CTestDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CTestDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CTestDLLView

#ifdef _DEBUG
void CTestDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CTestDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDLLDoc* CTestDLLView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDLLDoc)));
	return (CTestDLLDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CTestDLLView


void CTestDLLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	OnLeftButton(this, point);

	CView::OnLButtonDown(nFlags, point);
}


void CTestDLLView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	OnRightButton(this, point);
	CView::OnRButtonDown(nFlags, point);
}
