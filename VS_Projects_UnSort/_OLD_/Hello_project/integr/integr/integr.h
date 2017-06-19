
// integr.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CintegrApp:
// О реализации данного класса см. integr.cpp
//

class CintegrApp : public CWinApp
{
public:
	CintegrApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CintegrApp theApp;