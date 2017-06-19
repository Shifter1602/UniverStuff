
// Aplication2.h : главный файл заголовка для приложения Aplication2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CAplication2App:
// О реализации данного класса см. Aplication2.cpp
//

class CAplication2App : public CWinApp
{
public:
	CAplication2App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAplication2App theApp;
