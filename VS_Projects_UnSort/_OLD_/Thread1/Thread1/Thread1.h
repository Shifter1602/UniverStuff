
// Thread1.h : главный файл заголовка для приложения Thread1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CThread1App:
// О реализации данного класса см. Thread1.cpp
//

class CThread1App : public CWinApp
{
public:
	CThread1App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThread1App theApp;
