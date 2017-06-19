// IU1_Iunkin.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CIU1_IunkinApp:
// See IU1_Iunkin.cpp for the implementation of this class
//

class CIU1_IunkinApp : public CWinApp
{
public:
	CIU1_IunkinApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CIU1_IunkinApp theApp;