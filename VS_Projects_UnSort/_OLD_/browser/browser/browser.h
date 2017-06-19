
// browser.h : главный файл заголовка для приложения browser
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CbrowserApp:
// О реализации данного класса см. browser.cpp
//

class CbrowserApp : public CWinApp
{
public:
	CbrowserApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CbrowserApp theApp;
