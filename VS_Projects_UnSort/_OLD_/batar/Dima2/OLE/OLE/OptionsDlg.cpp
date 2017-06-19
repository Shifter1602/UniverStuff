// OptionsDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "OLE.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// диалоговое окно COptionsDlg

IMPLEMENT_DYNAMIC(COptionsDlg, CDialog)

COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
	, m_string(_T(""))
	, m_colour(0)
{
	m_colour = 0;
}

COptionsDlg::~COptionsDlg()
{
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STRING, m_string);
	DDX_Radio(pDX, IDC_COLOUR, m_colour);
	DDX_Check(pDX, IDC_CHECK1, m_hcentre);
	DDX_Check(pDX, IDC_CHECK2, m_vcentre);
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
END_MESSAGE_MAP()


// обработчики сообщений COptionsDlg

