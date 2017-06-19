
// Money1Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Money1.h"
#include "Money1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMoney1Dlg




CMoney1Dlg::CMoney1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMoney1Dlg::IDD, pParent)
	, m_euro(0)
	, m_usd(0)
	, m_sum1(0)
	, m_sum2(0)
	, m_radio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoney1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_RADIO1, m_raido);
	DDX_Text(pDX, IDC_EDIT1, m_euro);
	DDX_Text(pDX, IDC_EDIT2, m_usd);
	DDX_Text(pDX, IDC_EDIT3, m_sum1);
	DDX_Text(pDX, IDC_EDIT4, m_sum2);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
}

BEGIN_MESSAGE_MAP(CMoney1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMoney1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMoney1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ����������� ��������� CMoney1Dlg

BOOL CMoney1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMoney1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMoney1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMoney1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMoney1Dlg::OnBnClickedButton1()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData();
	switch(m_radio)
	{
	case 0: m_sum2=m_sum1/m_euro; break;
	case 1: m_sum2=m_sum1*m_euro; break;
	case 2: m_sum2=m_sum1/m_usd; break;
	case 3: m_sum2=m_sum1*m_usd; break;
	}
	UpdateData(FALSE);
}


void CMoney1Dlg::OnBnClickedButton2()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData();
	m_sum2=0;
	m_sum1=0;
	m_euro=0;
	m_usd=0;
	UpdateData(FALSE);
}
