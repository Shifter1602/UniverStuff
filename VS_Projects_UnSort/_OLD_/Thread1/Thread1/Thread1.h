
// Thread1.h : ������� ���� ��������� ��� ���������� Thread1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CThread1App:
// � ���������� ������� ������ ��. Thread1.cpp
//

class CThread1App : public CWinApp
{
public:
	CThread1App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThread1App theApp;
