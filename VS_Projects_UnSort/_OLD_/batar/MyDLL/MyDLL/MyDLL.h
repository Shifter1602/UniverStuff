// MyDLL.h: главный файл заголовка для DLL MyDLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMyDLLApp
// Про реализацию данного класса см. MyDLL.cpp
//

class CMyDLLApp : public CWinApp
{
public:
	CMyDLLApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
