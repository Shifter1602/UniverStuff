
// Browser.h : ������� ���� ��������� ��� ���������� Browser
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CBrowserApp:
// � ���������� ������� ������ ��. Browser.cpp
//

class CBrowserApp : public CWinApp
{
public:
	CBrowserApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBrowserApp theApp;
