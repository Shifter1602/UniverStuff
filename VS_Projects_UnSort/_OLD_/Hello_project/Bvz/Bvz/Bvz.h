
// Bvz.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CBvzApp:
// О реализации данного класса см. Bvz.cpp
//

class CBvzApp : public CWinApp
{
public:
	CBvzApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CBvzApp theApp;