
// browserView.cpp : реализация класса CbrowserView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(IDC_GOBUTTON, &CbrowserView::OnBnClickedGobutton)
END_MESSAGE_MAP()

// создание/уничтожение CbrowserView

CbrowserView::CbrowserView()
{
	// TODO: добавьте код создания

}

CbrowserView::~CbrowserView()
{
}

BOOL CbrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CbrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://google.ru"),NULL,NULL);
}


// печать CbrowserView



// диагностика CbrowserView

#ifdef _DEBUG
void CbrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CbrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CbrowserDoc* CbrowserView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbrowserDoc)));
	return (CbrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CbrowserView


void CbrowserView::OnBnClickedGobutton()
{
	// TODO: добавьте свой код обработчика уведомлений
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
