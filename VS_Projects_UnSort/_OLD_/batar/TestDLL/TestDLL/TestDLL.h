
// TestDLL.h : главный файл заголовка для приложения TestDLL
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы

extern "C" _declspec(dllimport)
	void OnLeftButton(CWnd* pWnd, CPoint& point);
extern "C" _declspec(dllimport)
    void OnRightButton(CWnd* pWnd, CPoint& point);



// CTestDLLApp:
// О реализации данного класса см. TestDLL.cpp
//

class CTestDLLApp : public CWinApp
{
public:
	CTestDLLApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestDLLApp theApp;
