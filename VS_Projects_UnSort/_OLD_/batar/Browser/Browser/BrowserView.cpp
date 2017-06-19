
// BrowserView.cpp : реализаци€ класса CBrowserView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
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
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(IDC_BUTTON1, &CBrowserView::OnBnClickedButton)
END_MESSAGE_MAP()

// создание/уничтожение CBrowserView

CBrowserView::CBrowserView()
{
	// TODO: добавьте код создани€

}

CBrowserView::~CBrowserView()
{
}

BOOL CBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.un-fkt.ru"),NULL,NULL);
}


// печать CBrowserView



// диагностика CBrowserView

#ifdef _DEBUG
void CBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CBrowserDoc* CBrowserView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBrowserDoc)));
	return (CBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CBrowserView


void CBrowserView::OnBnClickedButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString strURL;
	CBrowserDoc* pDoc = GetDocument();
	// провер€ем, не пустой ли указатель
	ASSERT_VALID(pDoc);
	//	получаем ссылку на панель с адресом
	CWnd& rBar = ((CMainFrame*) AfxGetApp()->m_pMainWnd)->m_wndDlgBar;
	// считываем введенный в адресной строке текст в переменную
	rBar.GetDlgItemText(IDC_ADDRESS_EDIT, strURL);
	Navigate2(strURL, NULL, NULL);


}
