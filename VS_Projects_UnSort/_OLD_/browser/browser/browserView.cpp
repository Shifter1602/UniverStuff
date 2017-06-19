
// browserView.cpp : ���������� ������ CbrowserView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "browser.h"
#endif

#include "browserDoc.h"
#include "browserView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbrowserView

IMPLEMENT_DYNCREATE(CbrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CbrowserView, CHtmlView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(IDC_GOBUTTON, &CbrowserView::OnBnClickedGobutton)
END_MESSAGE_MAP()

// ��������/����������� CbrowserView

CbrowserView::CbrowserView()
{
	// TODO: �������� ��� ��������

}

CbrowserView::~CbrowserView()
{
}

BOOL CbrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CbrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://google.ru"),NULL,NULL);
}


// ������ CbrowserView



// ����������� CbrowserView

#ifdef _DEBUG
void CbrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CbrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CbrowserDoc* CbrowserView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbrowserDoc)));
	return (CbrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CbrowserView


void CbrowserView::OnBnClickedGobutton()
{
	// TODO: �������� ���� ��� ����������� �����������
	CString strURL;
	CbrowserDoc* pDoc = GetDocument();
	//Checking if pionter is NULL
	ASSERT_VALID(pDoc);
	//Getting ssylka on address panel
	CWnd & rBar = ((CMainFrame*)AfxGetApp()->m_pMainWnd)->m_wndDlgBar;
	//reading inputed address
	rBar.GetDlgItemText(IDC_ADDRESSBOX,strURL);
	Navigate2(strURL,NULL,NULL);

}
