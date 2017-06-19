
// 228.h : главный файл заголовка для приложения 228
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMy228App:
// О реализации данного класса см. 228.cpp
//

class CMy228App : public CWinApp
{
public:
	CMy228App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy228App theApp;
