
// wwwDlg.cpp : implementation file
//

#include "stdafx.h"
#include "www.h"
#include "wwwDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwwwDlg dialog




CwwwDlg::CwwwDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CwwwDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwwwDlg::DoDataExchange(CDataExchange* pDX)
{
CDialogEx::DoDataExchange(pDX);
DDX_Control(pDX, IDC_BUTTON1, m_b1);
	}

BEGIN_MESSAGE_MAP(CwwwDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CwwwDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CwwwDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CwwwDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CwwwDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CwwwDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CwwwDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CwwwDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CwwwDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CwwwDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &CwwwDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CwwwDlg message handlers

BOOL CwwwDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CwwwDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CwwwDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwwwDlg::OnBnClickedOk()
	{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	}

int but_id_9[] ={IDC_BUTTON1,IDC_BUTTON2,IDC_BUTTON3,IDC_BUTTON4,IDC_BUTTON5,IDC_BUTTON6,IDC_BUTTON7,IDC_BUTTON8};

void CwwwDlg::OnBnClickedButton1()
	{
	// TODO: Add your control notification handler code here
	int i[]={but_id_9[0],but_id_9[1],but_id_9[3]};

	CWnd *p =GetDlgItem(i[0]);
	MessageBox((LPCTSTR)p->GetCurrentMessage());
	//m_b1.GetTextMargin()
	//p[0]->SetWindowTextW((LPCTSTR("")));
	}


void CwwwDlg::OnBnClickedButton2()
	{
	// TODO: Add your control notification handler code here

	}


void CwwwDlg::OnBnClickedButton3()
	{
	// TODO: Add your control notification handler code here
	}


void CwwwDlg::OnBnClickedButton4()
	{
	// TODO: Add your control notification handler code here
	}


void CwwwDlg::OnBnClickedButton5()
	{
	// TODO: Add your control notification handler code here
	}

void CwwwDlg::OnBnClickedButton6()
	{
	// TODO: Add your control notification handler code here
	}


void CwwwDlg::OnBnClickedButton7()
	{
	// TODO: Add your control notification handler code here
	}


void CwwwDlg::OnBnClickedButton8()
	{
	// TODO: Add your control notification handler code here
	}


void CwwwDlg::OnBnClickedButton9()
	{
	// TODO: Add your control notification handler code here
	}

