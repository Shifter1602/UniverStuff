
// Dialog.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CDialogApp:
// О реализации данного класса см. Dialog.cpp
//

class CDialogApp : public CWinApp
{
public:
	CDialogApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CDialogApp theApp;