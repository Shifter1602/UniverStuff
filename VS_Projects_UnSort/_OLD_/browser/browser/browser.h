
// browser.h : ������� ���� ��������� ��� ���������� browser
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CbrowserApp:
// � ���������� ������� ������ ��. browser.cpp
//

class CbrowserApp : public CWinApp
{
public:
	CbrowserApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CbrowserApp theApp;
