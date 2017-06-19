
// Hello_project.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CHello_projectApp:
// О реализации данного класса см. Hello_project.cpp
//

class CHello_projectApp : public CWinApp
{
public:
	CHello_projectApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CHello_projectApp theApp;