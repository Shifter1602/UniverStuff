
// Aplication2.h : ������� ���� ��������� ��� ���������� Aplication2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CAplication2App:
// � ���������� ������� ������ ��. Aplication2.cpp
//

class CAplication2App : public CWinApp
{
public:
	CAplication2App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAplication2App theApp;
