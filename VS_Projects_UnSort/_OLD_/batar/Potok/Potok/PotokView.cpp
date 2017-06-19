
// PotokView.cpp : ���������� ������ CPotokView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Potok.h"
#endif

#include "PotokDoc.h"
#include "PotokView.h"
#include <complex> // ���������� ���������� ��� ������ � ������������ �������
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPotokView

IMPLEMENT_DYNCREATE(CPotokView, CView)

BEGIN_MESSAGE_MAP(CPotokView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� CPotokView

CPotokView::CPotokView()
{
	// TODO: �������� ��� ��������

}

CPotokView::~CPotokView()
{
}

BOOL CPotokView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CPotokView

void CPotokView::OnDraw(CDC* /*pDC*/)
{
	CPotokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CPotokView

BOOL CPotokView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CPotokView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CPotokView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CPotokView

#ifdef _DEBUG
void CPotokView::AssertValid() const
{
	CView::AssertValid();
}

void CPotokView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPotokDoc* CPotokView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPotokDoc)));
	return (CPotokDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CPotokView


void CPotokView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	// ��������� ���������� ������ � �������� ������
	CClientDC dc(this); // �������� �������� ���������� ����� ���� �������������
	RECT rect; // ������������� ��� ���������� ������� ����
	GetClientRect(&rect); // ��������� � ���������� ������� ���� �������������
	complex<double> c(-0.012, 0.74); // ��������� ������������ �����
	for (int i=rect.left; i<rect.right; i++)
		for (int j=rect.top; i<rect.bottom; j++)
		{
		   complex<double> x(0.0001*i, 0.0001*j);
		   for (int n=0; n<100; n++)
		   {
			   if (abs(x)>100) break;
			   else x=pow(x,2)+c;
		   if (abs(x)<1)
			   dc.SetPixel(i,j,RGB(0,0,255));
		   else dc.SetPixel(i,i,RGB(2*abs(x),255,255));
		}
		}
	CView::OnLButtonDown(nFlags, point);
}
