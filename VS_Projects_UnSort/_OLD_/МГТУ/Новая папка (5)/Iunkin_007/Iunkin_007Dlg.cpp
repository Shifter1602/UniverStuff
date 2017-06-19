// Iunkin_007Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Iunkin_007.h"
#include "Iunkin_007Dlg.h"
#include ".\iunkin_007dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define Size 1000
CDialog dlg1,dlg2,dlg3;
CDC*dc1,*dc2,*dc3;
//int A[Size],B[Size],C[Size];
int *A,*B,*C;
int N,bk=0;

// CAboutDlg dialog used for App About






void Clear()
{	
	dlg1.ShowWindow(SW_HIDE);
	dlg1.ShowWindow(SW_SHOW);
	dlg2.ShowWindow(SW_HIDE);
	dlg2.ShowWindow(SW_SHOW);
	dlg3.ShowWindow(SW_HIDE);
	dlg3.ShowWindow(SW_SHOW);
	
}
	


void SortP(int *A, int N)
{
	for(int i=N;i>1;i--)
		for(int j=0;j<i-1;j++)
			if(A[j]>A[j+1])
			{	
				dc1->SetPixel(j,A[j],bk);
				dc1->SetPixel(j+1,A[j+1],bk);
				int tmp=A[j];
				A[j]=A[j+1];
				A[j+1]=tmp;
				dc1->SetPixel(j,A[j],0);
				dc1->SetPixel(j+1,A[j+1],0);
			}
}

void SortIns(int *B, int N)
{
    for (int i = 1; i < Size; i++)
{
	
    int temp = B[i];
    for (int j = i - 1; j >= 0; j--)
    {
        if (B[j] < temp)
            break;
		dc2->SetPixel(j,B[j],bk);
		dc2->SetPixel(j+1,B[j+1],bk);
        B[j + 1] = B[j];
        B[j] = temp;
		dc2->SetPixel(j,B[j],0);
		dc2->SetPixel(j+1,B[j+1],0);
    }
}

}

void SortQck(int *C, int first, int last)
{
	int i = first, j = last, x = C[(first + last) / 2];
 
    do {
        while (C[i] < x) i++;
        while (C[j] > x) j--;
 
        if(i <= j) {
			dc3->SetPixel(i,C[i],bk);
			dc3->SetPixel(j,C[j],bk);	
            if (C[i] > C[j]) 
				{
					
					int tmp=C[i];
					C[i]=C[j];
					C[j]=tmp;
					
				}
				i++;
				j--;
			dc3->SetPixel(i,C[i],0);
			dc3->SetPixel(j,C[j],0);	
			}
    } while (i <= j);
 
    if (i < last)
        SortQck(C, i, last);
    if (first < j)
        SortQck(C, first, j);
}



 DWORD __stdcall StartSortP(void*p)
{
	SortP((int*)p,Size);
	delete p;
	return 0;
}


DWORD __stdcall StartSortIns(void*p)
{
	SortIns((int*)p,Size);
	delete p;
	return 0;
}

DWORD __stdcall StartSortQck(void*p)
{
	SortQck((int*)p,0,Size-1);
	delete p;
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


// CIunkin_007Dlg dialog



CIunkin_007Dlg::CIunkin_007Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIunkin_007Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIunkin_007Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIunkin_007Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// CIunkin_007Dlg message handlers

BOOL CIunkin_007Dlg::OnInitDialog()
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
	
	dlg1.Create(IDD_DIALOG1);
	dlg2.Create(IDD_DIALOG2);
	dlg3.Create(IDD_DIALOG3);
	dlg1.MoveWindow(200,0,1000,256);
	dlg2.MoveWindow(200,256,1000,256);
	dlg3.MoveWindow(200,512,1000,256);
	dlg1.ShowWindow(SW_SHOW);
	dlg2.ShowWindow(SW_SHOW);
	dlg3.ShowWindow(SW_SHOW);
	dc1=dlg1.GetDC();
	dc2=dlg2.GetDC();
	dc3=dlg3.GetDC();
	MoveWindow(0,1,200,700);
	bk=dc1->GetPixel(0,0);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIunkin_007Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIunkin_007Dlg::OnPaint() 
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
HCURSOR CIunkin_007Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CIunkin_007Dlg::OnBnClickedButton1()
{
	Clear();A=new int [Size];B=new int [Size];C=new int [Size];
	for(int i=0;i<Size;i++)
	{	
		A[i]=rand()%256;
		
		B[i]=rand()%256;
		
		C[i]=rand()%256;
		//dc1->SetPixel(i,A[i],0);
		//dc2->SetPixel(i,B[i],0);
		//dc3->SetPixel(i,C[i],0);
	}
	//SortP(A,Size);
	//SortIns(B,Size);
	
	for(int i=0;i<Size;i++)
	{
		dc1->SetPixel(i,A[i],0);
		dc2->SetPixel(i,B[i],0);
		dc3->SetPixel(i,C[i],0);
	}
	HANDLE H1= CreateThread(0,0,StartSortP,A,0,0);
	SetThreadPriority(H1,-15);
	SetThreadAffinityMask(H1,1);
	CloseHandle(H1);
	HANDLE H2= CreateThread(0,0,StartSortIns,B,0,0);
	SetThreadPriority(H2,1);
	SetThreadAffinityMask(H2,1);
	CloseHandle(H2);
	HANDLE H3= CreateThread(0,0,StartSortQck,C,0,0);
	SetThreadPriority(H3,2);
	SetThreadAffinityMask(H3,1);
	CloseHandle(H3);
}
