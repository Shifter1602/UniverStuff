// RectDiag.cpp : implementation file
//

#include "stdafx.h"
#include "Commando.h"
#include "RectDiag.h"
#include "afxdialogex.h"


// RectDiag dialog

IMPLEMENT_DYNAMIC(RectDiag, CDialog)

RectDiag::RectDiag(CWnd* pParent /*=NULL*/)
	: CDialog(RectDiag::IDD, pParent)
{

m_a = 0;
m_b = 0;
m_c = 0;
m_d = 0;
	}

RectDiag::~RectDiag()
{
}

void RectDiag::DoDataExchange(CDataExchange* pDX)
{
CDialog::DoDataExchange(pDX);
DDX_Text(pDX, IDC_EDIT1, m_a);
DDX_Text(pDX, IDC_EDIT2, m_b);
DDX_Text(pDX, IDC_EDIT3, m_c);
DDX_Text(pDX, IDC_EDIT4, m_d);
	}


BEGIN_MESSAGE_MAP(RectDiag, CDialog)
	ON_BN_CLICKED(IDOK, &RectDiag::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &RectDiag::OnBnClickedButton1)
END_MESSAGE_MAP()


// RectDiag message handlers


void RectDiag::OnBnClickedOk()
	{
	// TODO: Add your control notification handler code here
	}


void RectDiag::OnBnClickedButton1()
	{
	// TODO: Add your control notification handler code here
	CClientDC dc(this->GetOwner());
	dc.Rectangle(m_a,m_b,m_c,m_d);
	}
