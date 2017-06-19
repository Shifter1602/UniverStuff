// MyDLL.cpp: определяет процедуры инициализации для DLL.
//

#include "stdafx.h"
#include "MyDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC. Это означает, что
//		он должен быть первым оператором 
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMyDLLApp
//Exported function
extern "C" _declspec(dllexport)
	void OnLeftButton(CWnd* pWnd, CPoint& point)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//declaring peremenn for accessing to window context in that LeftButtonClick
	CClientDC dc(pWnd);
	char s[30];
	//copying text in symbol array
	wsprintf((LPSTR)s,(LPCSTR)("DLL Left Click"));
	dc.TextOut(point.x,point.y,(LPCSTR)s,strlen(s));
}


BEGIN_MESSAGE_MAP(CMyDLLApp, CWinApp)
END_MESSAGE_MAP()


// создание CMyDLLApp

CMyDLLApp::CMyDLLApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMyDLLApp

CMyDLLApp theApp;


// инициализация CMyDLLApp

BOOL CMyDLLApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
