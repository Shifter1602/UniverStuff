
// Bvz.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CBvzApp:
// � ���������� ������� ������ ��. Bvz.cpp
//

class CBvzApp : public CWinApp
{
public:
	CBvzApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CBvzApp theApp;