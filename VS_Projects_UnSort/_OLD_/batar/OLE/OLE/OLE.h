
// OLE.h : ������� ���� ��������� ��� ���������� OLE
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// COLEApp:
// � ���������� ������� ������ ��. OLE.cpp
//

class COLEApp : public CWinApp
{
public:
	COLEApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COLEApp theApp;
