
// Thread2.h : главный файл заголовка для приложения Thread2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CThread2App:
// О реализации данного класса см. Thread2.cpp
//

class CThread2App : public CWinApp
{
public:
	CThread2App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThread2App theApp;
