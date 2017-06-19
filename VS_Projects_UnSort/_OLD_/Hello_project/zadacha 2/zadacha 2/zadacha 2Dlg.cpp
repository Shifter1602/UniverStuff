
// zadacha 2Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "zadacha 2.h"
#include "zadacha 2Dlg.h"
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


// ���������� ���� Czadacha2Dlg




Czadacha2Dlg::Czadacha2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Czadacha2Dlg::IDD, pParent)
	, m_euro(0)
	, m_usd(0)
	, m_su1(0)
	, m_su2(0)
	, m_radio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Czadacha2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_euro);
	DDX_Text(pDX, IDC_EDIT2, m_usd);
	DDX_Text(pDX, IDC_EDIT4, m_su1);
	DDX_Text(pDX, IDC_EDIT1, m_su2);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
}

BEGIN_MESSAGE_MAP(Czadacha2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Czadacha2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Czadacha2Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ����������� ��������� Czadacha2Dlg

BOOL Czadacha2Dlg::OnInitDialog()
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
	Czadacha2Dlg::m_euro=70.0;
	Czadacha2Dlg::m_usd=62.0;
	UpdateData(FALSE);

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void Czadacha2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Czadacha2Dlg::OnPaint()
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
HCURSOR Czadacha2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Czadacha2Dlg::OnBnClickedButton1()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData();
	switch(m_radio)
	{
	case 0:
		m_su2=m_su1/m_euro;
		break;
	case 1:
		m_su2=m_su1*m_euro;
		break;
	case 2:
		m_su2=m_su1/m_usd;
		break;
	case 3:
		m_su2=m_su1*m_usd;
		break;
	}
	UpdateData(FALSE);
}



void Czadacha2Dlg::OnBnClickedButton2()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData();
	m_su1=m_su2=0;
	UpdateData(FALSE);
}
