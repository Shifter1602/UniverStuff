
// Dialog.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CDialogApp:
// � ���������� ������� ������ ��. Dialog.cpp
//

class CDialogApp : public CWinApp
{
public:
	CDialogApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CDialogApp theApp;