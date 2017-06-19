
// integrDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "integr.h"
#include "integrDlg.h"
#include "afxdialogex.h"
#include "math.h"

double f(double x)
{
	return x*x;
}


double CalcSimps(double a, double b, double c, double d, double h)
{
	double x=a+h, result=0;
	while(x<b)
	{
		result+=4*(c*f(x)+d);
		x+=h;
		result+=2*(c*f(x)+d);
		x+=h;
	}
	result=(h/3.0)*(result+c*(f(a)-f(b)));
	return result;
}




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CintegrDlg




CintegrDlg::CintegrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CintegrDlg::IDD, pParent)
	, m_a(0)
	, m_b(0)
	, m_c(0)
	, m_d(0)
	, m_step(0)
	, m_integr(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CintegrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_a);
	DDX_Text(pDX, IDC_EDIT2, m_b);
	DDX_Text(pDX, IDC_EDIT4, m_c);
	DDX_Text(pDX, IDC_EDIT3, m_d);
	DDX_Text(pDX, IDC_EDIT5, m_step);
	DDX_Text(pDX, IDC_EDIT6, m_integr);
}

BEGIN_MESSAGE_MAP(CintegrDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CintegrDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CintegrDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// обработчики сообщений CintegrDlg

BOOL CintegrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CintegrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CintegrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CintegrDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	m_a = m_b = m_c = m_d = m_step = m_integr = 0;
	UpdateData(FALSE);
}


void CintegrDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	m_integr=CalcSimps(m_a,m_b,m_c,m_d,m_step);
	UpdateData(FALSE);


	
}



 