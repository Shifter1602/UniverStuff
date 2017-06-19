// Yunkin_01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Yunkin_01.h"
#include "Yunkin_01Dlg.h"
#include ".\yunkin_01dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
 int Global = 100;
 CRITICAL_SECTION MySect;
 HANDLE MyMutex;
 DWORD __stdcall MyFunc(void*p)
{ 
	CListBox*List=(CListBox*)p;
	List->ResetContent();
	char z[10];
	for(int i=0;i<20;i++)
		{
			Global++;
			Sleep(100);
			Global--;
			sprintf(z,"%i",Global);
			List->AddString(z);
		}
	return 0;
}

DWORD __stdcall MyFunc1(void*p)
{
	CListBox*List=(CListBox*)p;
	List->ResetContent();
	char z[10];
	for(int i=0;i<20;i++)
		{
			EnterCriticalSection(&MySect);
				Global++;
				Sleep(100);
				Global--;
				sprintf(z,"%i",Global);
			LeaveCriticalSection(&MySect);
			List->AddString(z);
		}
	return 0;
}


DWORD __stdcall MyFunc2(void*p)
{
	
	CListBox*List=(CListBox*)p;
	List->ResetContent();
	char z[10];
	for(int i=0;i<20;i++)
		{	WaitForSingleObject(MyMutex,INFINITE);
				Global++;
				Sleep(100);
				Global--;
				sprintf(z,"%i",Global);
			ReleaseMutex(MyMutex);
			
			List->AddString(z);
		}
	return 0;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CYunkin_01Dlg dialog



CYunkin_01Dlg::CYunkin_01Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYunkin_01Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYunkin_01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, s);
	DDX_Control(pDX, IDC_LIST2, z);
	DDX_Control(pDX, IDC_LIST3, x);
}

BEGIN_MESSAGE_MAP(CYunkin_01Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_LBN_SELCHANGE(IDC_LIST1, OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
END_MESSAGE_MAP()


// CYunkin_01Dlg message handlers

BOOL CYunkin_01Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitializeCriticalSection(&MySect);
	MyMutex=CreateMutex(0,FALSE,"It is my mutex!!!");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CYunkin_01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CYunkin_01Dlg::OnPaint() 
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
HCURSOR CYunkin_01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CYunkin_01Dlg::OnLbnSelchangeList1()
{	
}

void CYunkin_01Dlg::OnBnClickedButton1()
{
	CreateThread(0,0,MyFunc,&s,0,0);
	CreateThread(0,0,MyFunc,&z,0,0);
	CreateThread(0,0,MyFunc,&x,0,0);
}

void CYunkin_01Dlg::OnBnClickedButton2()
{
	CreateThread(0,0,MyFunc1,&s,0,0);
	CreateThread(0,0,MyFunc1,&z,0,0);
	CreateThread(0,0,MyFunc1,&x,0,0);
}

void CYunkin_01Dlg::OnClose()
{
	DeleteCriticalSection(&MySect);
	CloseHandle(MyMutex);

	CDialog::OnClose();
}

void CYunkin_01Dlg::OnBnClickedButton3()
{
	CreateThread(0,0,MyFunc2,&s,0,0);
	CreateThread(0,0,MyFunc2,&z,0,0);
	CreateThread(0,0,MyFunc2,&x,0,0);
}
