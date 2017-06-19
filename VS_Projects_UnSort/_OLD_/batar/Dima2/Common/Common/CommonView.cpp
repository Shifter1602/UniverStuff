
// CommonView.cpp : ���������� ������ CCommonView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCommonView::OnFilePrintPreview)
	ON_COMMAND(IDC_SMALLBUTTON, OnSmallButton)
	ON_COMMAND(IDC_LARGEBUTTON, OnLargeButton)
	ON_COMMAND(IDC_LISTBUTTON, OnListButton)
	ON_COMMAND(IDC_REPORTBUTTON, OnReportButton)
	ON_COMMAND(IDC_BOLDBUTTON, OnBoldButton)
	ON_COMMAND(IDC_LEFTBUTTON, OnLeftButton)
	ON_COMMAND(IDC_RIGHTBUTTON, OnRightButton)
	ON_COMMAND(IDC_CENTERBUTTON, OnCenterButton)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_HSCROLL()

END_MESSAGE_MAP()

// ��������/����������� CCommonView

CCommonView::CCommonView()
	: m_timer(FALSE)
{
	// TODO: �������� ��� ��������

}

CCommonView::~CCommonView()
{
}

BOOL CCommonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// ��������� CCommonView

void CCommonView::OnDraw(CDC* pDC)
{
	CCommonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
	pDC->TextOut(20, 22, "�������� ���������");
	pDC->TextOut(270, 22, "�������� ���������");
	pDC->TextOut(20, 102, "�����. ���.");
	pDC->TextOut(160, 102, "������ �����������");
	pDC->TextOut(20, 240, "������");
	pDC->TextOut(180, 240, "����������� ��������� ����");
	pDC->TextOut(520, 22, "IP-�����");
	pDC->TextOut(520, 102, "����");
	pDC->TextOut(520, 240, "���������");
}

void CCommonView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: ����������� ������ ������ ����� �������������
	sizeTotal.cx = 720;
	sizeTotal.cy = 500;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// ������ CCommonView


void CCommonView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCommonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CCommonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CCommonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
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


// ����������� CCommonView

#ifdef _DEBUG
void CCommonView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCommonView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCommonDoc* CCommonView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommonDoc)));
	return (CCommonDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CCommonView


int CCommonView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �������� ������������������ ��� ��������
	m_progressbar.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|PBS_SMOOTH, CRect(20, 40, 250, 80), this, IDC_PROGRESSBAR);
	m_progressbar.SetRange(1,100);
	m_progressbar.SetStep(1);
	m_progressbar.SetPos(1);
	m_timer=FALSE; // ������ ��������

	m_trackbar.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_BOTH|TBS_HORZ, CRect(270, 40, 450, 80), this, IDC_TRACKBAR);
	m_trackbar.SetRange(0, 100, TRUE);
	m_trackbar.SetTicFreq(10); // ������� �����
	m_trackbar.SetLineSize(1); // ����� ���
	m_trackbar.SetPageSize(10); // �������� ���

	m_ipaddress.Create(WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(520, 40, 700, 65), this, IDC_IPADDRESS);

	m_day.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|DTS_SHORTDATEFORMAT, CRect(520, 120, 700, 150), this, IDC_DAY);

	m_buddy.Create(WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(50, 120, 110, 160), this, IDC_BUDDY);
	m_updown.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_SETBUDDYINT|UDS_ARROWKEYS, CRect(0, 0, 0, 0), this, IDC_UPDOWN);
	m_updown.SetBuddy(&m_buddy);
	m_updown.SetRange(1,100);
	m_updown.SetPos(50);

	//��������� ������ ����������� ��� ������ ��������
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

	// ��������� ������� �������
	LV_COLUMN lvcolumn;
	lvcolumn.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	lvcolumn.fmt = LVCFMT_CENTER;
	lvcolumn.cx = 90;
	
	lvcolumn.iSubItem = 0;
	lvcolumn.pszText = "���.0";
	m_list.InsertColumn(0, &lvcolumn);

	lvcolumn.iSubItem = 1;
	lvcolumn.pszText = "���.1";
	m_list.InsertColumn(1, &lvcolumn);

	lvcolumn.iSubItem = 2;
	lvcolumn.pszText = "���.2";
	m_list.InsertColumn(2, &lvcolumn);
	
	// ��������� �������� � ������
    LV_ITEM lvitem;
	lvitem.mask = LVIF_TEXT|LVIF_IMAGE|LVIF_STATE;
	lvitem.state = 0;
	lvitem.stateMask = 0;
	lvitem.iImage = 0;

	lvitem.iItem = 0;
	lvitem.iSubItem = 0;
	lvitem.pszText = "����. 0.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(0, 1, "�������� 0.1");
	m_list.SetItemText(0, 2, "�������� 0.2");

	lvitem.iImage = 1;
	lvitem.iItem = 1;
	lvitem.iSubItem = 0;
	lvitem.pszText = "����. 1.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(1, 1, "�������� 1.1");
	m_list.SetItemText(1, 2, "�������� 1.2");

	lvitem.iImage = 2;
	lvitem.iItem = 2;
	lvitem.iSubItem = 0;
	lvitem.pszText = "����. 2.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(2, 1, "�������� 2.1");
	m_list.SetItemText(2, 2, "�������� 2.2");

	lvitem.iImage = 3;
	lvitem.iItem = 3;
	lvitem.iSubItem = 0;
	lvitem.pszText = "����. 3.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(3, 1, "�������� 3.1");
	m_list.SetItemText(3, 2, "�������� 3.2");
	
	lvitem.iImage = 4;
	lvitem.iItem = 4;
	lvitem.iSubItem = 0;
	lvitem.pszText = "����. 4.0";
    m_list.InsertItem(&lvitem);
	m_list.SetItemText(4, 1, "�������� 4.1");
	m_list.SetItemText(4, 2, "�������� 4.2");

	// ������ ��� ���������� ������ ������
	m_smallbutton.Create("������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 120, 500, 140), this, IDC_SMALLBUTTON);
	m_largebutton.Create("�������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 140, 500, 160), this, IDC_LARGEBUTTON);
	m_listbutton.Create("������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 160, 500, 180), this, IDC_LISTBUTTON);
	m_reportbutton.Create("�������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(430, 180, 500, 200), this, IDC_REPORTBUTTON);
	
	
	m_treeimagelist.Create(13, 13, FALSE, 1, 0);
 hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON2));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON3));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON4));
	m_treeimagelist.Add(hIcon);
	hIcon = LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON5));
	m_treeimagelist.Add(hIcon);
	//��������� ������ ��������
m_tree.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_EDITLABELS ,
	CRect(20,260,165,360),this,IDC_TREEVIEW);
m_tree.SetImageList(&m_treeimagelist,TVSIL_NORMAL);//�������� ������ �����������

//������� �������� �������
TVITEM tvitem;  //��������� ������ �������� ������
	tvitem.mask = TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvitem.pszText= "������";
	tvitem.cchTextMax = 7;
	tvitem.iImage=0;
	tvitem.iSelectedImage=1;
	TVINSERTSTRUCT tvinsert; //��������� ��� ������� ����� ������� � ������
	tvinsert.hParent=TVI_ROOT; //��� �������� �������,� ���� ��� ��������
	tvinsert.hInsertAfter=TVI_FIRST; //��� ������ ������ �� ������ ������ ��������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hRoot = m_tree.InsertItem(&tvinsert); //�������� �������� ������
	//������� ������� ����������� ���������
	tvitem.pszText= "������� 0";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 1;
	tvitem.iSelectedImage= 2;
	tvinsert.hParent=hRoot; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_FIRST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem0 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 0.0";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 0;
	tvitem.iSelectedImage= 0;
	tvinsert.hParent=hItem0; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_FIRST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem1 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 0.1";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 1;
	tvitem.iSelectedImage= 1;
	tvinsert.hParent=hItem0; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_LAST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem2 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 0.2";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 2;
	tvitem.iSelectedImage= 2;
	tvinsert.hParent=hItem0; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_LAST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem3 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 1";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 1;
	tvitem.iSelectedImage= 2;
	tvinsert.hParent=hRoot; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_LAST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem4 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 1.1";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 0;
	tvitem.iSelectedImage= 0;
	tvinsert.hParent=hItem4; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_LAST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem5 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 1.2";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 1;
	tvitem.iSelectedImage= 1;
	tvinsert.hParent=hItem4; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_LAST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem6 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	tvitem.pszText= "������� 1.3";
	tvitem.cchTextMax = 10;
	tvitem.iImage= 2;
	tvitem.iSelectedImage= 2;
	tvinsert.hParent=hItem4; //��� �������,� �������� ��������-������
	tvinsert.hInsertAfter=TVI_LAST; //��� ������ ������ �� ������ ������ ������
	tvinsert.item = tvitem; //��������� ���������,���������� �������� ������������ �������
	HTREEITEM hItem7 = m_tree.InsertItem(&tvinsert); //�������� ����� �������

	// ������� ����������� ��������� ����
	m_richedit.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|ES_AUTOVSCROLL|ES_MULTILINE, CRect(180, 260, 398, 360), this, IDC_RICHEDITVIEW);
	m_bold.Create("������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(400, 270, 490, 290), this, IDC_BOLDBUTTON);
	m_left.Create("�����", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(400, 290, 490, 310), this, IDC_LEFTBUTTON);
	m_right.Create("������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(400, 310, 490, 330), this, IDC_RIGHTBUTTON);
	m_center.Create("�� ������", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(400, 330, 490, 350), this, IDC_CENTERBUTTON);

	
	// ��������� ������� "���������"
	m_month.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|DTS_SHORTDATEFORMAT, CRect(520, 260, 700, 420), this, IDC_MONTH);

	return 0;


}


void CCommonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
    if (m_timer==TRUE)
	{
		KillTimer(1); // ������� ������ � ������� 1
		m_timer=FALSE;
	}
	else
	{
		SetTimer(1,1, NULL); // ������� ������ � ������� 1 � ���������� ������������ 500 ��
		m_timer=TRUE;
	}
	CScrollView::OnLButtonDown(nFlags, point);
}


void CCommonView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	m_progressbar.StepIt(); // � �������� ��������� ���������� �������� ���� ���
	CScrollView::OnTimer(nIDEvent);
}


void CCommonView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	CSliderCtrl* pSlider = (CSliderCtrl*) pScrollBar;
	if (pSlider == &m_trackbar)
	{
	int position = pSlider->GetPos(); // �������� ������� ��������� �������
	char s[10];
	wsprintf(s, "%d  ", position);
	CClientDC dc(this);
	dc.TextOut(420, 22, s);
	}
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
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

void CCommonView::OnReportButton()
{
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_NOSORTHEADER|LVS_EDITLABELS);
}


BOOL CCommonView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: �������� ������������������ ��� ��� ����� �������� ������
	LV_DISPINFO* lvdispinfo = (LV_DISPINFO*) lParam;
	if (lvdispinfo->hdr.code == LVN_BEGINLABELEDIT) // ���� ������������ ������� ����� �������������� �������
		CEdit* pEdit = m_list.GetEditControl(); // �������� ��������� �� ������������� ������
	else if (lvdispinfo->hdr.code == LVN_ENDLABELEDIT)
	{
		// ���� ���� ������� �������� ������ � ������ �������� �� ��������, � �� � ������ �����
		if ((lvdispinfo->item.pszText != NULL) && (lvdispinfo->item.iItem !=-1))
			// ��������� � �������� ������� ������� �����, ��������� �������������
			m_list.SetItemText(lvdispinfo->item.iItem, 0, lvdispinfo->item.pszText);
	}

	TV_DISPINFO* tvdispinfo = (TV_DISPINFO*) lParam;
	if (tvdispinfo->hdr.code == TVN_BEGINLABELEDIT) // ���� ������������ ������� ����� �������������� �������
		CEdit* pEdit = m_tree.GetEditControl(); // �������� ��������� �� ������������� ������
	else if (tvdispinfo->hdr.code == TVN_ENDLABELEDIT)
	{
		// ���� ���� ������� �������� ������ � ������ �������� �� ��������, � �� � ������ �����
		if (tvdispinfo->item.pszText != NULL)
			// ��������� � �������� ������� ������� �����, ��������� �������������
			m_tree.SetItemText(tvdispinfo->item.hItem, tvdispinfo->item.pszText);
	}

	return CScrollView::OnNotify(wParam, lParam, pResult);
}

void CCommonView::OnBoldButton()
{
	CHARFORMAT charformat;
	charformat.cbSize = sizeof(CHARFORMAT); // ���������� ������ ���������
	charformat.dwMask = CFM_BOLD; // �������� �� ������ "����������"
	m_richedit.GetSelectionCharFormat(charformat); // ��������� � ��������� ��������� CHARFORMAT
	// ������ �������� ����������� ��������� ������
	if (charformat.dwEffects & CFM_BOLD) // ���� � ���������� ��������� ����� ��� ����������
		charformat.dwEffects = 0; // �������� ���������� �����
	else charformat.dwEffects = CFE_BOLD; // ��������� ���������� �����
	m_richedit.SetSelectionCharFormat(charformat); // ��������� ��� ����������� ��������� ������
	// ������ �������� � ������������ � ���������� ���������� ��������� CHARFORMAT
	m_richedit.SetFocus(); // ������� ����� ���������� � ������� "����������� ��������� ����"

}

void CCommonView::OnLeftButton()
{
	PARAFORMAT paraformat;
	paraformat.cbSize = sizeof(PARAFORMAT);
	paraformat.dwMask = PFM_ALIGNMENT;
	paraformat.wAlignment = PFA_LEFT;
	m_richedit.SetParaFormat(paraformat);
	m_richedit.SetFocus();
}

void CCommonView::OnRightButton()
{
    PARAFORMAT paraformat;
	paraformat.cbSize = sizeof(PARAFORMAT);
	paraformat.dwMask = PFM_ALIGNMENT;
	paraformat.wAlignment = PFA_RIGHT;
	m_richedit.SetParaFormat(paraformat);
	m_richedit.SetFocus();
}

void CCommonView::OnCenterButton()
{
	PARAFORMAT paraformat;
	paraformat.cbSize = sizeof(PARAFORMAT);
	paraformat.dwMask = PFM_ALIGNMENT;
	paraformat.wAlignment = PFA_CENTER;
	m_richedit.SetParaFormat(paraformat);
	m_richedit.SetFocus();
}
