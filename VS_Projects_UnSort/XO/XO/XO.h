
// XO.h : main header file for the XO application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CXOApp:
// See XO.cpp for the implementation of this class
//

class CXOApp : public CWinApp
{
public:
	CXOApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CXOApp theApp;
