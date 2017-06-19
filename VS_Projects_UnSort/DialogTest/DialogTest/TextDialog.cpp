// TextDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DialogTest.h"
#include "TextDialog.h"
#include "afxdialogex.h"


// TextDialog dialog

IMPLEMENT_DYNAMIC(TextDialog, CDialogEx)

TextDialog::TextDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(TextDialog::IDD, pParent)
	, m_str(_T(""))
	{

}

TextDialog::~TextDialog()
{
}

void TextDialog::DoDataExchange(CDataExchange* pDX)
{
CDialogEx::DoDataExchange(pDX);
DDX_Control(pDX, IDC_EDIT1, m_cEdit1);
DDX_Text(pDX, IDC_EDIT1, m_str);
	}


BEGIN_MESSAGE_MAP(TextDialog, CDialogEx)
END_MESSAGE_MAP()


// TextDialog message handlers
