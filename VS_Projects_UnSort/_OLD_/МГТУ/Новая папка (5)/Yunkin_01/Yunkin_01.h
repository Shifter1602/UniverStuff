// Yunkin_01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CYunkin_01App:
// See Yunkin_01.cpp for the implementation of this class
//

class CYunkin_01App : public CWinApp
{
public:
	CYunkin_01App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CYunkin_01App theApp;