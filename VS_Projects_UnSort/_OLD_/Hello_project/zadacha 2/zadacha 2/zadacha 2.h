
// zadacha 2.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// Czadacha2App:
// � ���������� ������� ������ ��. zadacha 2.cpp
//

class Czadacha2App : public CWinApp
{
public:
	Czadacha2App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern Czadacha2App theApp;