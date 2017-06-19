// Iunkin_005Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Iunkin_005.h"
#include "Iunkin_005Dlg.h"
#include ".\iunkin_005dlg.h"
#include "math.h"
#define MyMessage WM_USER+10




#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDC* dc;
BOOL MustStop=true,
	 Running=FALSE,
	 Running1=FALSE;
	 
int Limit =256;
long double a1=-1,a2=1,b1=-1,b2=1;
int A[400][300];
int mode=0;
int MyFunc(long double cx, long double cy)
{
	long double x=cx, y=cy, xn;
	int n=0;
	while((n<Limit)&&(x<3.14)&&(x>-3.14))
	{
		xn=x;
		x=x*x-y*y+cx;
		y=2*xn*y+cy;
		n++;
	}
	return n;
}
int MyColor(int n)
{
	switch(mode)
	{
	case 0: return RGB(n,n,n);
	case 1: return RGB(n,2*n,3*n);
	case 2: return RGB(128+127*cos(n*0.10),128+127*sin(n*0.11),128+127*cos(n*0.08));
	case 3: return RGB(n*n*n,128+15*sin(n*0.4)*cos(n*0.43),127+tan(n*0.7));
	}

}

DWORD __stdcall StartDraw(void *p)
	{
		CIunkin_005Dlg * MyDlg;
		MyDlg=(CIunkin_005Dlg*)p;
		MyDlg->Draw();
		return 0;
	}

DWORD __stdcall StartDraw1(void *p)
	{
		CIunkin_005Dlg * MyDlg;
		MyDlg=(CIunkin_005Dlg*)p;
		MyDlg->Draw1();
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


// CIunkin_005Dlg dialog



CIunkin_005Dlg::CIunkin_005Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIunkin_005Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIunkin_005Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Combo1);
	DDX_Control(pDX, IDC_EDIT1, Edit1);
}

BEGIN_MESSAGE_MAP(CIunkin_005Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_MESSAGE(MyMessage,OnMyMessage)
END_MESSAGE_MAP()


// CIunkin_005Dlg message handlers

BOOL CIunkin_005Dlg::OnInitDialog()
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
	ParaDraw();
	ParaDraw1();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIunkin_005Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIunkin_005Dlg::OnPaint() 
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
	ReDraw();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIunkin_005Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CIunkin_005Dlg::OnBnClickedButton1()
{
dc=GetDC();
for(int i=0;i<400;i++)
	for(int j=0;j<300;j++)
//dc->SetPixel(i,j,RGB(i,i*j*j,j*i));
dc->SetPixel(i,j,RGB(i*i*j,i*j*i*i,i*i*i*i*j*j));
}

void CIunkin_005Dlg::OnBnClickedButton2()
{
	dc=GetDC();
	for(int i=0;i<360;i++)
	{
		dc->SetPixel(i,150-150*sin(i*3.14/180.0),RGB(i*i,i*i*i*i,i*i*i*i));
		dc->LineTo(i,200-150*sin(i*3.14/180.0));
	}

}

void CIunkin_005Dlg::OnBnClickedButton3()
{
dc=GetDC();
	for(int i=0;i<3600;i++)
	{
		dc->SetPixel(150+150*sin(i*3.14/400.0),150+150*sin(i*3.14/300.0),0);
		
	}
}

void CIunkin_005Dlg::OnBnClickedButton4()
{
ParaDraw();
ParaDraw1();
}

void CIunkin_005Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	long double mx= point.x*(a2-a1)/400+a1,
				my= point.y*(b2-b1)/300+b1,
				w=a2-a1,
				h=b2-b1;
	if ((nFlags & MK_SHIFT )!=0) {w=w/2;h=h/2;} 
	else;
	a1=mx-w/4;
	a2=mx+w/4;
	b1=my-h/4;
	b2=my+h/4;
	ParaDraw();
	ParaDraw1();


	CDialog::OnLButtonDown(nFlags, point);
}

void CIunkin_005Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	long double mx= point.x*(a2-a1)/400+a1,
				my= point.y*(b2-b1)/300+b1,
				w=a2-a1,
				h=b2-b1;
	if ((nFlags & MK_SHIFT )!=0) {w=w*2;h=h*2;}
	else;
	a1=mx-w;
	a2=mx+w;
	b1=my-h;
	b2=my+h;
	ParaDraw();
	ParaDraw1();


	CDialog::OnRButtonDown(nFlags, point);
}

void CIunkin_005Dlg::Draw(void)
{
Running=TRUE;
dc=GetDC();
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<300;j++)
				{
					int n =MyFunc(i*(a2-a1)/400+a1,j*(b2-b1)/300+b1);
					A[i][j]=n;
					//dc->SetPixel(i,j,MyColor(n));
					if(MustStop){Running=FALSE;return;}
				}
		//OnMyMessage(i,0);
		PostMessage(MyMessage,i,0);
		//PostMessage(MyMessage_1,j,0);
	}
	Running=FALSE;
}

void CIunkin_005Dlg::Draw1(void)
{
Running1=TRUE;
dc=GetDC();
	for(int i=200;i<400;i++)
	{
		for(int j=0;j<300;j++)
				{
					int n =MyFunc(i*(a2-a1)/400+a1,j*(b2-b1)/300+b1);
					A[i][j]=n;
					//dc->SetPixel(i,j,MyColor(n));
					if(MustStop){Running1=FALSE;return;}
				}
		//OnMyMessage(i,0);
		PostMessage(MyMessage,i,0);
		//PostMessage(MyMessage_1,j,0);
	}
	Running1=FALSE;
}


void CIunkin_005Dlg::ReDraw(void)
{
	dc=GetDC();
	for(int i=0;i<400;i++)
		for(int j=0;j<300;j++)
	{
		int n=A[i][j];
		dc->SetPixel(i,j,MyColor(n));
	}
}

void CIunkin_005Dlg::OnCbnSelchangeCombo1()
{
	mode=Combo1.GetCurSel();
	ReDraw();
}



void CIunkin_005Dlg::ParaDraw(void)
{
	MustStop=TRUE;
	while(Running)Sleep(100);
	MustStop=FALSE;
	CloseHandle(
		CreateThread(0,0,StartDraw,this,0,0));
}

void CIunkin_005Dlg::ParaDraw1(void)
{
	MustStop=TRUE;
	while(Running)Sleep(100);
	MustStop=FALSE;
	CloseHandle(
		CreateThread(0,0,StartDraw1,this,0,0));
}

void CIunkin_005Dlg::OnEnChangeEdit1()
{
char z[256];
Edit1.GetWindowText(z,256);
sscanf(z,"%i",&Limit);
ParaDraw();
ParaDraw1();
}

LRESULT CIunkin_005Dlg::OnMyMessage(WPARAM W, LPARAM L)
{
	//отрисовать столбец №W
	dc=GetDC();
	for(int j=0;j<300;j++)
	{
		dc->SetPixel(W,j,MyColor(A[W][j]));
	}

	return LRESULT();
}

/*LRESULT CIunkin_005Dlg::OnMyMessage_1(WPARAM W, LPARAM L)
{//отрисовать столбец №W
	dc=GetDC();
	for(int j=150;j<300;j++)
	{
		dc->SetPixel(W,j,MyColor(A[W][j]));
	}

	return LRESULT();
}*/



