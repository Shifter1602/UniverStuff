
// MDI_test.h : главный файл заголовка для приложения MDI_test
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMDI_testApp:
// О реализации данного класса см. MDI_test.cpp
//

class CMDI_testApp : public CWinApp
{
public:
	CMDI_testApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDI_testApp theApp;
