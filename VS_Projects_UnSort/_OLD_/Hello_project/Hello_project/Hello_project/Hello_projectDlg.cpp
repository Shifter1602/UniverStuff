
// Hello_projectDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Hello_project.h"
#include "Hello_projectDlg.h"
#include "afxdialogex.h"
#include "string.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CHello_projectDlg




CHello_projectDlg::CHello_projectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHello_projectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_edit = _T("");
}

void CHello_projectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CHello_projectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHello_projectDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ����������� ��������� CHello_projectDlg

BOOL CHello_projectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CHello_projectDlg::OnPaint()
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
HCURSOR CHello_projectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHello_projectDlg::OnBnClickedButton1()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData();
	MessageBox("Hello " + m_edit,"Hello",MB_ICONINFORMATION);
}
