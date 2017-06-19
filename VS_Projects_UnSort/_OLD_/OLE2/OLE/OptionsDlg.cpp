// OptionsDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "OLE.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// диалоговое окно OptionsDlg

IMPLEMENT_DYNAMIC(OptionsDlg, CDialogEx)

OptionsDlg::OptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(OptionsDlg::IDD, pParent)
{

}

OptionsDlg::~OptionsDlg()
{
}

void OptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OptionsDlg, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений OptionsDlg
