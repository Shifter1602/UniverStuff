// GameForm.cpp : implementation file
//

#include "stdafx.h"
#include "XO.h"
#include "GameForm.h"
#include "afxdialogex.h"


// GameForm dialog

IMPLEMENT_DYNAMIC(GameForm, CDialog)

GameForm::GameForm(CWnd* pParent /*=NULL*/)
	: CDialog(GameForm::IDD, pParent)
{

}

GameForm::~GameForm()
{
}

void GameForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameForm, CDialog)
END_MESSAGE_MAP()


// GameForm message handlers
