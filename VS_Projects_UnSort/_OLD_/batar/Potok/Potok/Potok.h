
// Potok.h : ������� ���� ��������� ��� ���������� Potok
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CPotokApp:
// � ���������� ������� ������ ��. Potok.cpp
//

class CPotokApp : public CWinApp
{
public:
	CPotokApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPotokApp theApp;
