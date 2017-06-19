
// Browser.h : главный файл заголовка для приложения Browser
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CBrowserApp:
// О реализации данного класса см. Browser.cpp
//

class CBrowserApp : public CWinApp
{
public:
	CBrowserApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBrowserApp theApp;
