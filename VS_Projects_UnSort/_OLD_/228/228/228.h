
// 228.h : ������� ���� ��������� ��� ���������� 228
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMy228App:
// � ���������� ������� ������ ��. 228.cpp
//

class CMy228App : public CWinApp
{
public:
	CMy228App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy228App theApp;
