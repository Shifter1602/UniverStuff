
// BrowserView.cpp : ���������� ������ CBrowserView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Browser.h"
#endif

#include "BrowserDoc.h"
#include "BrowserView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBrowserView

IMPLEMENT_DYNCREATE(CBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CBrowserView, CHtmlView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(IDC_BUTTON1, &CBrowserView::OnBnClickedButton)
END_MESSAGE_MAP()

// ��������/����������� CBrowserView

CBrowserView::CBrowserView()
{
	// TODO: �������� ��� ��������

}

CBrowserView::~CBrowserView()
{
}

BOOL CBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.un-fkt.ru"),NULL,NULL);
}


// ������ CBrowserView



// ����������� CBrowserView

#ifdef _DEBUG
void CBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CBrowserDoc* CBrowserView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBrowserDoc)));
	return (CBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CBrowserView


void CBrowserView::OnBnClickedButton()
{
	// TODO: �������� ���� ��� ����������� �����������
	CString strURL;
	CBrowserDoc* pDoc = GetDocument();
	// ���������, �� ������ �� ���������
	ASSERT_VALID(pDoc);
	//	�������� ������ �� ������ � �������
	CWnd& rBar = ((CMainFrame*) AfxGetApp()->m_pMainWnd)->m_wndDlgBar;
	// ��������� ��������� � �������� ������ ����� � ����������
	rBar.GetDlgItemText(IDC_ADDRESS_EDIT, strURL);
	Navigate2(strURL, NULL, NULL);


}
