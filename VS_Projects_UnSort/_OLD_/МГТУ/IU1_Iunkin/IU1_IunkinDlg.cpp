// IU1_IunkinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IU1_Iunkin.h"
#include "IU1_IunkinDlg.h"
#include ".\iu1_iunkindlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIU1_IunkinDlg dialog

int fact (int n)
{
	if (n<=1)
	return 1;
	else
	return n*fact(n-1);
}

DWORD __stdcall Counter (void*p)
{	CIU1_IunkinDlg*dlg;
	dlg=(CIU1_IunkinDlg*)p;
	char z[256];
	int i;
	for(i=0;i<1000000;i++)
	{
		sprintf(z,"%i",i);
		dlg->SetWindowText(z);
	}
	return 0;

}

CIU1_IunkinDlg::CIU1_IunkinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIU1_IunkinDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIU1_IunkinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_1);
	DDX_Control(pDX, IDC_EDIT2, Edit_2);
}

BEGIN_MESSAGE_MAP(CIU1_IunkinDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnBnClickedButton8)
END_MESSAGE_MAP()


// CIU1_IunkinDlg message handlers

BOOL CIU1_IunkinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

void CIU1_IunkinDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIU1_IunkinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CIU1_IunkinDlg::OnBnClickedButton1()
{
	SetWindowText("Hello World");
	//Edit_1.SetWindowText("Hello Edit_1!");
	char z[256],s[256];
	Edit_1.GetWindowText(z,256);
	Edit_2.GetWindowText(s,256);
	//Edit_2.SetWindowText(z);
	//
	//sscanf(z,"%i",&a);
	//a=a+1;
	//sprintf(z,"%i",a);
	//Edit_1.SetWindowText(z);
	//
	int a,b,c;
	sscanf(z,"%i",&a);
	sscanf(s,"%i",&b);
	c=a+b;
	sprintf(z,"%i",c);
	Edit_1.SetWindowText(z);
	

}

void CIU1_IunkinDlg::OnBnClickedButton2()
{
	char z[256],s[256];
	Edit_1.GetWindowText(z,256);
	Edit_2.GetWindowText(s,256);
	int a,b,c;
	sscanf(z,"%i",&a);
	sscanf(s,"%i",&b);
	c=a-b;
	sprintf(z,"%i",c);
	Edit_1.SetWindowText(z);
}

void CIU1_IunkinDlg::OnBnClickedButton3()
{
	char z[256],s[256];
	Edit_1.GetWindowText(z,256);
	Edit_2.GetWindowText(s,256);
	int a,b,c;
	sscanf(z,"%i",&a);
	sscanf(s,"%i",&b);
	c=a*b;
	sprintf(z,"%i",c);
	Edit_1.SetWindowText(z);
}

void CIU1_IunkinDlg::OnBnClickedButton4()
{
	char z[256],s[256];
	Edit_1.GetWindowText(z,256);
	Edit_2.GetWindowText(s,256);
	int a,b,c;
	sscanf(z,"%i",&a);
	sscanf(s,"%i",&b);
	if(b==0)Edit_1.SetWindowText("b = 0 !!!!!");
	else{
	c=a/b;
	sprintf(z,"%i",c);
	Edit_1.SetWindowText(z);
}
}
void CIU1_IunkinDlg::OnBnClickedButton5()//counter
{	char z[256];
	int i;
	for(i=0;i<1000000;i++)
	{
		sprintf(z,"%i",i);
		SetWindowText(z);
	}

}

void CIU1_IunkinDlg::OnBnClickedButton6()
{
char z[256];int a,b;
Edit_1.GetWindowText(z,256);
sscanf(z,"%i",&a);
b=fact(a);
sprintf(z,"%i",b);
Edit_2.SetWindowText(z);
}

void CIU1_IunkinDlg::OnBnClickedButton7()
{
Counter(this);
}

void CIU1_IunkinDlg::OnBnClickedButton8()
{
CreateThread(0,0,Counter,this,0,0);
}
