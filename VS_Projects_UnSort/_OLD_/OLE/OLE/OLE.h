
// OLE.h : главный файл заголовка для приложения OLE
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// COLEApp:
// О реализации данного класса см. OLE.cpp
//

class COLEApp : public CWinApp
{
public:
	COLEApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COLEApp theApp;
