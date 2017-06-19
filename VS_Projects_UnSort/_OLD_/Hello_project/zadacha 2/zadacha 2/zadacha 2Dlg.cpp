
// zadacha 2Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "zadacha 2.h"
#include "zadacha 2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно Czadacha2Dlg




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


// обработчики сообщений Czadacha2Dlg

BOOL Czadacha2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	Czadacha2Dlg::m_euro=70.0;
	Czadacha2Dlg::m_usd=62.0;
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Czadacha2Dlg::OnPaint()
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
HCURSOR Czadacha2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Czadacha2Dlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	m_su1=m_su2=0;
	UpdateData(FALSE);
}
