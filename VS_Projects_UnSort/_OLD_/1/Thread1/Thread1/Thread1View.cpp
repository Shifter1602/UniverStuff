
// Thread1View.cpp : ���������� ������ CThread1View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Thread1.h"
#endif

#include "Thread1Doc.h"
#include "Thread1View.h"
#include <complex>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThread1View

IMPLEMENT_DYNCREATE(CThread1View, CView)

BEGIN_MESSAGE_MAP(CThread1View, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� CThread1View

CThread1View::CThread1View()
{
	// TODO: �������� ��� ��������

}

CThread1View::~CThread1View()
{
}

BOOL CThread1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CThread1View

void CThread1View::OnDraw(CDC* /*pDC*/)
{
	CThread1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CThread1View

BOOL CThread1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CThread1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CThread1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CThread1View

#ifdef _DEBUG
void CThread1View::AssertValid() const
{
	CView::AssertValid();
}

void CThread1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThread1Doc* CThread1View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThread1Doc)));
	return (CThread1Doc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CThread1View


void CThread1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	CClientDC dc(this);
	RECT rect;
	GetClientRect(&rect);//��������� � ���������� ������� ���� �������������
	complex<double> c(-0.012, 0.74);//��������� ������������ �����
	for(int i=rect.left; i<=rect.right; i++)
		for(int j=rect.top; j<=rect.bottom; j++)
		{
			complex<double> x(0.0001*i, 0.0001*j);
			for(int n=0; n<100; n++)
			{
				if(abs(x)>100)
					break;
				else
					x=pow(x,2)+c;
				if(abs(x)<1)
					dc.SetPixel(i, j, RGB(0, 0, 255));
				else
				dc.SetPixel(i, j, RGB(2*abs(x), 255, 255));
			}
		}
	CView::OnLButtonDown(nFlags, point);
}
