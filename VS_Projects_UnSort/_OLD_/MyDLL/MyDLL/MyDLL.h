// MyDLL.h: ������� ���� ��������� ��� DLL MyDLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMyDLLApp
// ��� ���������� ������� ������ ��. MyDLL.cpp
//

class CMyDLLApp : public CWinApp
{
public:
	CMyDLLApp();

// ���������������
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
