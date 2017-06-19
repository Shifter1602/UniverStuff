
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
	ON_COMMAND(IDC_SMALLBUTTON, OnSmallButton)
	ON_COMMAND(IDC_LARGEBUTTON, OnLargeButton)
	ON_COMMAND(IDC_LISTBUTTON, OnListButton)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_HSCROLL()

END_MESSAGE_MAP()

// создание/уничтожение CCommonView

CCommonView::CCommonView()
	: m_timer(FALSE)
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

void CCommonView::OnDraw(CDC* pDC)
{
	CCommonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	pDC->TextOut(20, 22, "Линейный индикатор");
	pDC->TextOut(270, 22, "Линейный регулятор");
	pDC->TextOut(20, 102, "Инрем. рег.");
	pDC->TextOut(160, 102, "Список изображений");
	pDC->TextOut(20, 240, "Дерево");
	pDC->TextOut(180, 240, "Расширенное текстовое поле");
	pDC->TextOut(520, 22, "IP-адрес");
	pDC->TextOut(520, 102, "Дата");
	pDC->TextOut(520, 240, "Календарь");
}

void CCommonView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
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
	m_progressbar.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|PBS_SMOOTH, CRect(20, 40, 250, 80), this, IDC_PROGRESSBAR);
	m_progressbar.SetRange(1,100);
	m_progressbar.SetStep(1);
	m_progressbar.SetPos(1);
	m_timer=FALSE; // таймер выключен

	m_trackbar.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_BOTH|TBS_HORZ, CRect(270, 40, 450, 80), this, IDC_TRACKBAR);
	m_trackbar.SetRange(0, 100, TRUE);
	m_trackbar.SetTicFreq(10); // частота меток
	m_trackbar.SetLineSize(1); // малый шаг
	m_trackbar.SetPageSize(10); // большоей шаг

	m_ipaddress.Create(WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(520, 40, 700, 65), this, IDC_IPADDRESS);

	m_day.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|DTS_SHORTDATEFORMAT, CRect(520, 120, 700, 150), this, IDC_DAY);

	m_buddy.Create(WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(50, 120, 110, 160), this, IDC_BUDDY);
	m_updown.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_SETBUDDYINT|UDS_ARROWKEYS, CRect(0, 0, 0, 0), this, IDC_UPDOWN);
	m_updown.SetBuddy(&m_buddy);
	m_updown.SetRange(1,100);
	m_updown.SetPos(50);


	m_smallimagelist.Create(16, 16, FALSE, 1, 0);
	m_largeimagelist.Create(32, 32, FALSE, 1, 0);
	HICON hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_smallimagelist.Add(hIcon);
	m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON2));
	m_smallimagelist.Add(hIcon);
	m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON3));
	m_smallimagelist.Add(hIcon);
	m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON4));
	m_smallimagelist.Add(hIcon);
	m_largeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON5));
	m_smallimagelist.Add(hIcon);
	m_largeimagelist.Add(hIcon);

	m_list.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_NOSORTHEADER|LVS_EDITLABELS, CRect(160, 120, 430, 220), this, IDC_LIST);
	m_list.SetImageList(&m_smallimagelist, LVSIL_SMALL);
	m_list.SetImageList(&m_largeimagelist, LVSIL_NORMAL);

	// формируем колонки таблицы
	LV_COLUMN lvcolumn;
	lvcolumn.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	lvcolumn.fmt = LVCFMT_CENTER;
	lvcolumn.cx = 90;
	
	lvcolumn.iSubItem = 0;
	lvcolumn.pszText = "Кол.0";
	m_list.InsertColumn(0, &lvcolumn);

	lvcolumn.iSubItem = 1;
	lvcolumn.pszText = "Кол.1";
	m_list.InsertColumn(1, &lvcolumn);

	lvcolumn.iSubItem = 2;
	lvcolumn.pszText = "Кол.2";
	m_list.InsertColumn(2, &lvcolumn);
	
	// добавляем элементы в список
    LV_ITEM lvitem;
	lvitem.mask = LVIF_TEXT|LVIF_IMAGE|LVIF_STATE;
	lvitem.state = 0;
	lvitem.stateMask = 0;
	lvitem.iImage = 0;

	lvitem.iItem = 0;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Элем. 0.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(0, 1, "Свойство 0.1");
	m_list.SetItemText(0, 2, "Свойство 0.2");

	lvitem.iImage = 1;
	lvitem.iItem = 1;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Элем. 1.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(1, 1, "Свойство 1.1");
	m_list.SetItemText(1, 2, "Свойство 1.2");

	lvitem.iImage = 2;
	lvitem.iItem = 2;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Элем. 2.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(2, 1, "Свойство 2.1");
	m_list.SetItemText(2, 2, "Свойство 2.2");

	lvitem.iImage = 3;
	lvitem.iItem = 3;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Элем. 3.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(3, 1, "Свойство 3.1");
	m_list.SetItemText(3, 2, "Свойство 3.2");
	
	lvitem.iImage = 4;
	lvitem.iItem = 4;
	lvitem.iSubItem = 0;
	lvitem.pszText = "Элем. 4.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(4, 1, "Свойство 4.1");
	m_list.SetItemText(4, 2, "Свойство 4.2");

	// кнопки для управления стилем списка
	m_smallbutton.Create("Мелкие", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 120, 500, 140), this, IDC_SMALLBUTTON);
	m_largebutton.Create("Крупные", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 140, 500, 160), this, IDC_LARGEBUTTON);
	m_listbutton.Create("Список", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 160, 500, 180), this, IDC_LISTBUTTON);
	return 0;
}


void CCommonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
    if (m_timer==TRUE)
	{
		KillTimer(1); // удалить таймер с номером 1
		m_timer=FALSE;
	}
	else
	{
		SetTimer(1,1, NULL); // создать таймер с номером 1 и интервалом срабатывания 500 мс
		m_timer=TRUE;
	}
	CScrollView::OnLButtonDown(nFlags, point);
}


void CCommonView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_progressbar.StepIt(); // к текущему положению индикатора добавить один шаг
	CScrollView::OnTimer(nIDEvent);
}


void CCommonView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CSliderCtrl* pSlider = (CSliderCtrl*) pScrollBar;
	

	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
	int position = pSlider->GetPos(); // получаем текущее положение полозка
	char s[10];
	wsprintf(s, "%d  ", position);
	CClientDC dc(this);
	dc.TextOut(420, 22, s);
}

void CCommonView::OnSmallButton()
{
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_SMALLICON|LVS_NOSORTHEADER|LVS_EDITLABELS);
}

void CCommonView::OnLargeButton()
{
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_ICON|LVS_NOSORTHEADER|LVS_EDITLABELS);
}

void CCommonView::OnListButton()
{
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_LIST|LVS_NOSORTHEADER|LVS_EDITLABELS);
}




BOOL CCommonView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: добавьте специализированный код или вызов базового класса
	LV_DISPINFO* lvdispinfo = (LV_DISPINFO*) lParam;
	if (lvdispinfo->hdr.code == LVN_BEGINLABELEDIT) // если пользователь включил режим редактирования подписи
		CEdit* pEdit = m_list.GetEditControl(); // получаем указатель на редактируемый объект
	else if (lvdispinfo->hdr.code == LVN_ENDLABELEDIT)
	{
		// если была введена непустая строка и щелчок выполнен на элементе, а не в пустом месте
		if ((lvdispinfo->item.pszText != NULL) && (lvdispinfo->item.iItem !=-1))
			// закрепить в качестве подписи объекта текст, введенный пользователем
			m_list.SetItemText(lvdispinfo->item.iItem, 0, lvdispinfo->item.pszText);
	}
	return CScrollView::OnNotify(wParam, lParam, pResult);
}
