
// MDI1.h : ������� ���� ��������� ��� ���������� MDI1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMDI1App:
// � ���������� ������� ������ ��. MDI1.cpp
//

class CMDI1App : public CWinApp
{
public:
	CMDI1App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDI1App theApp;
