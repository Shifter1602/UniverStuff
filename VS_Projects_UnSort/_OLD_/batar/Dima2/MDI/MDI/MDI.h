
// MDI.h : главный файл заголовка для приложения MDI
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMDIApp:
// О реализации данного класса см. MDI.cpp
//

class CMDIApp : public CWinApp
{
public:
	CMDIApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDIApp theApp;
