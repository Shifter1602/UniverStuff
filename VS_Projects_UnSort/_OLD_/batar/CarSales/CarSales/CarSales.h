
// CarSales.h : ������� ���� ��������� ��� ���������� CarSales
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CCarSalesApp:
// � ���������� ������� ������ ��. CarSales.cpp
//

class CCarSalesApp : public CWinApp
{
public:
	CCarSalesApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCarSalesApp theApp;
