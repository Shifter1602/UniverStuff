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

// экспортируемые функции
extern "C" _declspec(dllexport)
	void OnLeftButton(CWnd* pWnd, CPoint& point)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CClientDC dc(pWnd); // объявляем переменную для доступа к контексту окна,
	// в котором выполнен щелчок левой кнопкой мыши
	char s[30];
    wsprintf((LPSTR)s, (LPCSTR)"DLL: щелчок левой кнопкой"); // копируем текст для вывода в массив 
	dc.TextOut(point.x, point.y, (LPCSTR)s, strlen(s)); // выводим строку в контекст в точке щелчка

}

extern "C" _declspec(dllexport)
    void OnRightButton(CWnd* pWnd, CPoint& point)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CClientDC dc(pWnd); // объявляем переменную для доступа к контексту окна,
	// в котором выполнен щелчок левой кнопкой мыши
	char s[30];
    wsprintf((LPSTR)s, (LPCSTR)"DLL: щелчок правой кнопкой"); // копируем текст для вывода в массив 
	dc.TextOut(point.x, point.y, (LPCSTR)s, strlen(s)); // выводим строку в контекст в точке щелчка

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
