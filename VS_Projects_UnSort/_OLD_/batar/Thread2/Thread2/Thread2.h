
// Thread2.h : ������� ���� ��������� ��� ���������� Thread2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CThread2App:
// � ���������� ������� ������ ��. Thread2.cpp
//

class CThread2App : public CWinApp
{
public:
	CThread2App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThread2App theApp;
