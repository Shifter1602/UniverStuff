
// TestDLL.h : ������� ���� ��������� ��� ���������� TestDLL
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������

extern "C" _declspec(dllimport)
	void OnLeftButton(CWnd* pWnd, CPoint& point);
extern "C" _declspec(dllimport)
    void OnRightButton(CWnd* pWnd, CPoint& point);



// CTestDLLApp:
// � ���������� ������� ������ ��. TestDLL.cpp
//

class CTestDLLApp : public CWinApp
{
public:
	CTestDLLApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestDLLApp theApp;
