
// MDI_test.h : ������� ���� ��������� ��� ���������� MDI_test
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMDI_testApp:
// � ���������� ������� ������ ��. MDI_test.cpp
//

class CMDI_testApp : public CWinApp
{
public:
	CMDI_testApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDI_testApp theApp;
