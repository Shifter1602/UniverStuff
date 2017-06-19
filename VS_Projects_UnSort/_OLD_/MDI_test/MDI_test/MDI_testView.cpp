
// MDI_testView.cpp : ���������� ������ CMDI_testView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MDI_test.h"
#endif

#include "MDI_testDoc.h"
#include "MDI_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDI_testView

IMPLEMENT_DYNCREATE(CMDI_testView, CView)

BEGIN_MESSAGE_MAP(CMDI_testView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ��������/����������� CMDI_testView

CMDI_testView::CMDI_testView()
{
	// TODO: �������� ��� ��������

}

CMDI_testView::~CMDI_testView()
{
}

BOOL CMDI_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CMDI_testView

void CMDI_testView::OnDraw(CDC* /*pDC*/)
{
	CMDI_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CMDI_testView

BOOL CMDI_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CMDI_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CMDI_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CMDI_testView

#ifdef _DEBUG
void CMDI_testView::AssertValid() const
{
	CView::AssertValid();
}

void CMDI_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDI_testDoc* CMDI_testView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDI_testDoc)));
	return (CMDI_testDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CMDI_testView
