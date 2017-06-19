
// Potok.h : главный файл заголовка для приложения Potok
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CPotokApp:
// О реализации данного класса см. Potok.cpp
//

class CPotokApp : public CWinApp
{
public:
	CPotokApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPotokApp theApp;
