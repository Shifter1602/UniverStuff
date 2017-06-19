
// Commando.h : main header file for the Commando application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCommandoApp:
// See Commando.cpp for the implementation of this class
//

class CCommandoApp : public CWinApp
{
public:
	CCommandoApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCommandoApp theApp;
