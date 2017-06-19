
// MDI1.h : главный файл заголовка для приложения MDI1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMDI1App:
// О реализации данного класса см. MDI1.cpp
//

class CMDI1App : public CWinApp
{
public:
	CMDI1App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDI1App theApp;
