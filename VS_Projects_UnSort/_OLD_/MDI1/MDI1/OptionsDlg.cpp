// OptionsDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "MDI1.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// диалоговое окно COptionsDlg

IMPLEMENT_DYNAMIC(COptionsDlg, CDialogEx)

COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COptionsDlg::IDD, pParent)
	, m_string(_T(""))
	, m_radio(0)
	, m_hcenter(FALSE)
	, m_vcenter(FALSE)
{

}

COptionsDlg::~COptionsDlg()
{
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STRING_EDIT, m_string);
	DDX_Radio(pDX, IDC_BLACK_RADIO, m_radio);
	DDX_Check(pDX, IDC_CHECK1, m_hcenter);
	DDX_Check(pDX, IDC_CHECK2, m_vcenter);
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений COptionsDlg


void COptionsDlg::OnEnChangeStringEdit()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}



