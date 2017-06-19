
// CommonView.cpp : реализация класса CCommonView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Common.h"
#endif

#include "CommonDoc.h"
#include "CommonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommonView

IMPLEMENT_DYNCREATE(CCommonView, CScrollView)

BEGIN_MESSAGE_MAP(CCommonView, CScrollView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCommonView::OnFilePrintPreview)

	ON_COMMAND(IDC_SMALLBUTTON,OnSmallButton)
	ON_COMMAND(IDC_LARGEBUTTON,OnLargeButton)
	ON_COMMAND(IDC_LISTBUTTON,OnListButton)
	ON_COMMAND(IDC_REPORTBUTTON,OnReportButton)

	ON_COMMAND(IDC_BOLDBUTTON,OnBold)
	ON_COMMAND(IDC_LEFTBUTTON,OnLeft)
	ON_COMMAND(IDC_RIGHTBUTTON,OnRight)
	ON_COMMAND(IDC_CENTERBUTTON,OnCenter)

	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// создание/уничтожение CCommonView

CCommonView::CCommonView()
	: m_timer(false)
{
	// TODO: добавьте код создания

}

CCommonView::~CCommonView()
{
}

BOOL CCommonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// рисование CCommonView

void CCommonView::OnDraw(CDC* pDC)//перерисовка окна
{
	CCommonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOut(20,22,"ProgressBar");
	pDC->TextOut(270,22,"TrackBar");
	pDC->TextOut(20,102,"SpinButton");
	pDC->TextOut(160,102,"ImageList");
	pDC->TextOut(220,240,"Tree");
	pDC->TextOut(180,240,"RichTextBox");
	pDC->TextOut(520,22,"IP adress");
	pDC->TextOut(520,102,"Date");
	pDC->TextOut(520,240,"Calendar");
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CCommonView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = 720; sizeTotal.cy = 500;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// печать CCommonView


void CCommonView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCommonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CCommonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CCommonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CCommonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCommonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CCommonView

#ifdef _DEBUG
void CCommonView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCommonView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCommonDoc* CCommonView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommonDoc)));
	return (CCommonDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CCommonView





int CCommonView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	m_progressbar.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | PBS_SMOOTH, CRect(20,40,250,80),this,IDC_PROGRESSBAR);
	m_progressbar.SetRange(1,500);
	m_progressbar.SetStep(1);
	m_progressbar.SetPos(50);
	//
	m_timer=FALSE; //timer switched off
	//
	m_trackbar.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | TBS_AUTOTICKS | TBS_BOTH | TBS_HORZ ,CRect(270,40,450,80),this, IDC_TRACKBAR);
	m_trackbar.SetRange(0,100, TRUE);//3rd parametr redrawing
	m_trackbar.SetTicFreq(10);//step of ticks
	m_trackbar.SetLineSize(1);
	m_trackbar.SetPageSize(10);
	//
	m_ipaddress.Create(WS_CHILD | WS_VISIBLE | WS_BORDER ,CRect(520,40,765,80),this, IDC_IPADDRESS);
	//
	m_date.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | DTS_SHORTDATEFORMAT, CRect(520,120,700,150),this, IDC_DATE);
	//
	m_buddy.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(50,120,110,140),this,IDC_BUDDY);
	m_updown.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | UDS_ALIGNRIGHT | UDS_SETBUDDYINT | UDS_ARROWKEYS, CRect(0,0,0,0),this,IDC_UPDOWN);
	m_updown.SetBuddy(&m_buddy);
	m_updown.SetRange(1,100);
	m_updown.SetPos(50);
	//
	m_smallimagelist.Create(16,16, FALSE, 1,0);
	m_largeimagelist.Create(32,32, FALSE, 1,0);
	HICON hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
		m_smallimagelist.Add(hIcon);
		m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON2));
		m_smallimagelist.Add(hIcon);
		m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON3));
		m_smallimagelist.Add(hIcon);
		m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON4));
		m_smallimagelist.Add(hIcon);
		m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON5));
		m_smallimagelist.Add(hIcon);
		m_largeimagelist.Add(hIcon);
	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_NOSORTHEADER | LVS_EDITLABELS, CRect(160,120,394,220),this,IDC_LIST);
	m_list.SetImageList(&m_smallimagelist, LVSIL_SMALL);
	m_list.SetImageList(&m_largeimagelist, LVSIL_NORMAL);
	//formiruem colonki tablitsy
	LV_COLUMN lvcolumn;
	lvcolumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvcolumn.fmt = LVCFMT_CENTER;
	lvcolumn.cx=75;

	lvcolumn.iSubItem = 0;
	lvcolumn.pszText = "Col 0";
	m_list.InsertColumn(0,&lvcolumn);

	lvcolumn.iSubItem = 1;
	lvcolumn.pszText = "Col 1";
	m_list.InsertColumn(1,&lvcolumn);

	lvcolumn.iSubItem = 2;
	lvcolumn.pszText = "Col 2";
	m_list.InsertColumn(2,&lvcolumn);
	//dobavlyaem elem v spisok

	LV_ITEM lvitem;
	lvitem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	lvitem.state = 0;
	lvitem.stateMask = 0;

	lvitem.iImage = 0;

	lvitem.iItem = 0;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Item 0";
	m_list.InsertItem(&lvitem);
	m_list.SetItemText(0,1,"Property 0.1");
	m_list.SetItemText(0,2,"Property 0.2");

	lvitem.iImage = 1;

	lvitem.iItem = 1;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Item 1";
	m_list.InsertItem(&lvitem);
	m_list.SetItemText(1,1,"Property 1.1");
	m_list.SetItemText(1,2,"Property 1.2");

	lvitem.iImage = 2;

	lvitem.iItem = 2;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Item 2";
	m_list.InsertItem(&lvitem);
	m_list.SetItemText(2,1,"Property 2.1");
	m_list.SetItemText(2,2,"Property 2.2");

	lvitem.iImage = 3;

	lvitem.iItem = 3;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Item 3";
	m_list.InsertItem(&lvitem);
	m_list.SetItemText(3,1,"Property 3.1");
	m_list.SetItemText(3,2,"Property 3.2");

	lvitem.iImage = 4;

	lvitem.iItem = 4;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Item 4";
	m_list.InsertItem(&lvitem);
	m_list.SetItemText(4,1,"Property 4.1");
	m_list.SetItemText(4,2,"Property 4.2");

	//knopki dlya upravl stilem spiska
	m_smallbutton.Create("Small",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(425,120,515,140),this,IDC_SMALLBUTTON);
	m_largebutton.Create("Large",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(425,145,515,165),this,IDC_LARGEBUTTON);
	m_listbutton.Create("List",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(425,170,515,190),this,IDC_LISTBUTTON);
	m_reportbutton.Create("Report",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(425,195,515,215),this,IDC_REPORTBUTTON);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//formiruem spisok izobr dlya dereva ob'ektov
	m_treeimagelist.Create(13,13, FALSE, 1,0);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON2));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON3));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON4));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON5));
	m_treeimagelist.Add(hIcon);
	//formiruem derevo ob'ektov
	m_tree.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_EDITLABELS, CRect(20,260,160,360),this,IDC_TREEVIEW);
	m_tree.SetImageList(&m_treeimagelist,TVSIL_NORMAL);//privyazka spiska izobr
	//sozdaem kornevoi element
	TVITEM tvitem;//struktura odnogo elementa dereva
	tvitem.mask= TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tvitem.pszText="Root";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=0;
	tvitem.iSelectedImage=1;
	TVINSERTSTRUCT tvinsert;//structura dlya vstavki novogo ob'ekta v derevo
	tvinsert.hParent = TVI_ROOT;
	tvinsert.hInsertAfter = TVI_FIRST;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hRoot = m_tree.InsertItem(&tvinsert);//insert root object
	//sozdaem podchin element
	tvitem.pszText="Elem 0";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=1;
	tvitem.iSelectedImage=2;
	tvinsert.hParent = hRoot;//elem u kot rodit - koren
	tvinsert.hInsertAfter = TVI_FIRST;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem0 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 1";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hRoot;//elem u kot rodit - koren
	tvinsert.hInsertAfter = hItem0;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem1 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 00";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hItem0;//elem u kot rodit - koren
	tvinsert.hInsertAfter = TVI_FIRST;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem00 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 01";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hItem0;//elem u kot rodit - koren
	tvinsert.hInsertAfter = hItem00;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem01 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 02";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hItem0;//elem u kot rodit - koren
	tvinsert.hInsertAfter = hItem01;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem02 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 10";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hItem1;//elem u kot rodit - koren
	tvinsert.hInsertAfter = TVI_FIRST;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem10 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 01";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hItem1;//elem u kot rodit - koren
	tvinsert.hInsertAfter = hItem10;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem11 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	tvitem.pszText="Elem 02";
	tvitem.cchTextMax=7;//Max length of text buffer
	tvitem.iImage=2;
	tvitem.iSelectedImage=3;
	tvinsert.hParent = hItem1;//elem u kot rodit - koren
	tvinsert.hInsertAfter = hItem11;//1yi ob'ekt na dannom urovne...
	tvinsert.item = tvitem;//Exemplyar struct soderzh opisanie vstav ob'ekta
	HTREEITEM hItem12 = m_tree.InsertItem(&tvinsert);//insert new object
	//////////////////////////////////////////////////////////////////////////
	//Creating RTB
	m_richedit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOVSCROLL | ES_MULTILINE , CRect(180,260,393,420),this,IDC_RICHTEXTBOX);
	m_bold.Create("Bold",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(400,260,490,280),this,IDC_BOLDBUTTON);
	m_left.Create("Left",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(400,285,490,305),this,IDC_LEFTBUTTON);
	m_right.Create("Right",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(400,310,490,330),this,IDC_RIGHTBUTTON);
	m_center.Create("Center",WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(400,335,490,355),this,IDC_CENTERBUTTON);
	//////////////////////////////////////////////////////////////////////////
	//Calendar
	m_month.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(520,260,700,420),this,IDC_MONTH);

	return 0;
}


void CCommonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if(m_timer==TRUE)

	{
		KillTimer(1); //delete timer number 1
		m_timer=FALSE;
	}
	else
	{
		SetTimer(1,1,NULL);// create timer 1 with 500 ms step
		m_timer=TRUE;
	}
	CScrollView::OnLButtonDown(nFlags, point);
}




void CCommonView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_progressbar.StepIt();// add step to current indicator position
	CScrollView::OnTimer(nIDEvent);
}


void CCommonView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CSliderCtrl* pSlider = (CSliderCtrl*) pScrollBar;//yavnoe privedenie tipov
	if(pSlider==&m_trackbar)
	{
		int position = pSlider->GetPos();
		char s[10];
		wsprintf(s,"%d  ", position);
		CClientDC dc(this);
		dc.TextOut(420,22,s);
	}



	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CCommonView::OnSmallButton()
{
	SetWindowLong(m_list.m_hWnd,GWL_STYLE,WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_NOSORTHEADER | LVS_EDITLABELS | LVS_SMALLICON);
}

void CCommonView::OnLargeButton()
{
	SetWindowLong(m_list.m_hWnd,GWL_STYLE,WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_NOSORTHEADER | LVS_EDITLABELS | LVS_ICON);
}

void CCommonView::OnListButton()
{
	SetWindowLong(m_list.m_hWnd,GWL_STYLE,WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_NOSORTHEADER | LVS_EDITLABELS | LVS_LIST);
}

void CCommonView::OnReportButton()
{
	SetWindowLong(m_list.m_hWnd,GWL_STYLE,WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_NOSORTHEADER | LVS_EDITLABELS );
}


void CCommonView::OnBold()
{
	CHARFORMAT charformat;
	charformat.cbSize = sizeof(CHARFORMAT);//opred razmer structury
	charformat.dwMask = CFM_BOLD;
	m_richedit.GetSelectionCharFormat(charformat);//zagruzhaem v exem struct charformat format symvola vydelennogo fragmenta texta
	if (charformat.dwEffects & CFM_BOLD)//esli v vydelenoom fragmente shrift uzhe bold
		charformat.dwEffects = 0;//cancel bold
	else 
		charformat.dwEffects = CFE_BOLD;//set bold
	m_richedit.SetSelectionCharFormat(charformat);//set format for selected text 
	m_richedit.SetFocus();//return focus of keyboard in rtb
}

void CCommonView::OnLeft()
{
PARAFORMAT paraformat;
paraformat.cbSize =sizeof(PARAFORMAT);
paraformat.dwMask = PFM_ALIGNMENT;
paraformat.wAlignment = PFA_LEFT;
m_richedit.SetParaFormat(paraformat);
m_richedit.SetFocus();
}

void CCommonView::OnRight()
{
	PARAFORMAT paraformat;
	paraformat.cbSize =sizeof(PARAFORMAT);
	paraformat.dwMask = PFM_ALIGNMENT;
	paraformat.wAlignment = PFA_RIGHT;
	m_richedit.SetParaFormat(paraformat);
	m_richedit.SetFocus();	
}

void CCommonView::OnCenter()
{
	PARAFORMAT paraformat;
	paraformat.cbSize =sizeof(PARAFORMAT);
	paraformat.dwMask = PFM_ALIGNMENT;
	paraformat.wAlignment = PFA_CENTER;
	m_richedit.SetParaFormat(paraformat);
	m_richedit.SetFocus();

}



BOOL CCommonView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: добавьте специализированный код или вызов базового класса
	LV_DISPINFO* lvdispinfo = (LV_DISPINFO *) lParam;
	//Esli pol'zovatel' vklyuchil rezhim redaktir podpisi
	if(lvdispinfo->hdr.code == LVN_BEGINLABELEDIT)
		//Poluchaem ukazatel na red obekt
		CEdit * pEdit = m_list.GetEditControl();
	//esli vvedena ne pustaya stroka i scheelchok vypolnen na elem a ne na pustom meste 
	else if(lvdispinfo->hdr.code == LVN_ENDLABELEDIT)
	{
		if((lvdispinfo->item.pszText != NULL) &&
			(lvdispinfo->item.iItem != -1))
			//zakrepit v kachestve podpisi obekta text vved polzovat
			m_list.SetItemText(lvdispinfo->item.iItem,0,lvdispinfo->item.pszText);
		
	}

	//////////////////////////////////////////////////////////////////////////
	TV_DISPINFO* tlvdispinfo = (TV_DISPINFO *) lParam;
	//Esli pol'zovatel' vklyuchil rezhim redaktir podpisi
	if(tlvdispinfo->hdr.code == TVN_BEGINLABELEDIT)
		//Poluchaem ukazatel na red obekt
		CEdit * pEdit = m_tree.GetEditControl();
	//esli vvedena ne pustaya stroka i scheelchok vypolnen na elem a ne na pustom meste 
	else if(tlvdispinfo->hdr.code == TVN_ENDLABELEDIT)
	{
		if(tlvdispinfo->item.pszText != NULL)
			//zakrepit v kachestve podpisi obekta text vved polzovat
			m_tree.SetItemText(tlvdispinfo->item.hItem,tlvdispinfo->item.pszText);

	}

	return CScrollView::OnNotify(wParam, lParam, pResult);
}
