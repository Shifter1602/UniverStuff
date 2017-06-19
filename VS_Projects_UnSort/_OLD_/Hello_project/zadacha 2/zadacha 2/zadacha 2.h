
// zadacha 2.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Czadacha2App:
// О реализации данного класса см. zadacha 2.cpp
//

class Czadacha2App : public CWinApp
{
public:
	Czadacha2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Czadacha2App theApp;