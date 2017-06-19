
// Thread2View.cpp : ���������� ������ CThread2View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Thread2.h"
#endif

#include "Thread2Doc.h"
#include "Thread2View.h"
#include "Thread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThread2View

IMPLEMENT_DYNCREATE(CThread2View, CView)

BEGIN_MESSAGE_MAP(CThread2View, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� CThread2View

CThread2View::CThread2View()
	: m_myThread(NULL)
{
	// TODO: �������� ��� ��������

}

CThread2View::~CThread2View()
{
}

BOOL CThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CThread2View

void CThread2View::OnDraw(CDC* /*pDC*/)
{
	CThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CThread2View

BOOL CThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CThread2View

#ifdef _DEBUG
void CThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThread2Doc* CThread2View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThread2Doc)));
	return (CThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CThread2View


void CThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	
	DWORD exitcode; // ���������� ��� ��������� ������� ������
	// ���� �������� ������ �����, ��� ��������� � ������� ����������������� �������,
	// ������� ������ ����� � ��������� ��� ������
	if (m_myThread) // ���� �������� ������ �����
	{
	   gExit.SetEvent(); // ���������� ���������������� �������
	   // ���������� ���������� ������ ������� ������
	   do
	     GetExitCodeThread(m_myThread->m_hThread, &exitcode); // �������� ��������� ������� ������
		while (exitcode == STILL_ACTIVE);
	Invalidate();  // ������������ ����
	UpdateWindow(); // �������� ����
	delete(m_myThread); 
	m_myThread = NULL; // ������� ������ �����
	}
	// ��������� ������ ����� ������
    m_myThread = AfxBeginThread(Fractal, this, THREAD_PRIORITY_NORMAL);
	m_myThread->m_bAutoDelete = FALSE; // ��������� ������������ ������� ������
	CView::OnLButtonDown(nFlags, point);

}
