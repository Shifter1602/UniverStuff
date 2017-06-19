// OptionsDlg.cpp: ���� ����������
//

#include "stdafx.h"
#include "MDI1.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// ���������� ���� COptionsDlg

IMPLEMENT_DYNAMIC(COptionsDlg, CDialogEx)

COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COptionsDlg::IDD, pParent)
	, m_string(_T(""))
	, m_radio(0)
{

}

COptionsDlg::~COptionsDlg()
{
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STRING_EDIT, m_string);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialogEx)
END_MESSAGE_MAP()


// ����������� ��������� COptionsDlg


void COptionsDlg::OnEnChangeStringEdit()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  �������� ��� �������� ����������
}



