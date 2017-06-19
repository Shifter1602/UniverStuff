
// CarSales.h : главный файл заголовка для приложения CarSales
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CCarSalesApp:
// О реализации данного класса см. CarSales.cpp
//

class CCarSalesApp : public CWinApp
{
public:
	CCarSalesApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCarSalesApp theApp;
