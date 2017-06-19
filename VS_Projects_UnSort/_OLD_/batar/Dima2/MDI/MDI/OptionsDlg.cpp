// OptionsDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "MDI.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// диалоговое окно COptionsDlg

IMPLEMENT_DYNAMIC(COptionsDlg, CDialogEx)

COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COptionsDlg::IDD, pParent)
	, m_string(_T(""))
	, m_radio1(0)
{

	m_colour = 0;
}

COptionsDlg::~COptionsDlg()
{
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STRING_EDIT, m_string);
	DDX_Radio(pDX, IDC_BLACK_RADIO, m_colour);
	DDX_Check(pDX, IDC_HCENTER_CHECK, m_hcentre);
	//  DDX_Check(pDX, IDC_VCENTER_CHECK, m_vcenter);
	DDX_Check(pDX, IDC_VCENTER_CHECK, m_vcentre);
}

BEGIN_MESSAGE_MAP(COptionsDlg, CDialogEx)
END_MESSAGE_MAP()







