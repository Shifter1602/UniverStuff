// Iunkin_005.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CIunkin_005App:
// See Iunkin_005.cpp for the implementation of this class
//

class CIunkin_005App : public CWinApp
{
public:
	CIunkin_005App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CIunkin_005App theApp;