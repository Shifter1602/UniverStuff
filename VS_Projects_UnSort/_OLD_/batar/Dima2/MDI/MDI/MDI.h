
// MDI.h : ������� ���� ��������� ��� ���������� MDI
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMDIApp:
// � ���������� ������� ������ ��. MDI.cpp
//

class CMDIApp : public CWinApp
{
public:
	CMDIApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDIApp theApp;
