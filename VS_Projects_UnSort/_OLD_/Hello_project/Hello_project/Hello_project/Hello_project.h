
// Hello_project.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CHello_projectApp:
// � ���������� ������� ������ ��. Hello_project.cpp
//

class CHello_projectApp : public CWinApp
{
public:
	CHello_projectApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CHello_projectApp theApp;