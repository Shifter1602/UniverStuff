// MyDLL.cpp: ���������� ��������� ������������� ��� DLL.
//

#include "stdafx.h"
#include "MyDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ���� ��� ���������� DLL ����������� ������� � ������������ DLL MFC,
//		��� �������, ���������������� �� ������ DLL-����������, ������� ��������� ������ �
//		MFC, ������ ��������� ������ AFX_MANAGE_STATE �
//		����� ������ �������.
//
//		��������:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// ���� ���������� �������
//		}
//
//		�����, ����� ������ ������ ��� ����������� � ������
//		������� �� ������ MFC. ��� ��������, ���
//		�� ������ ���� ������ ���������� 
//		������� � �������������� ���� ����� ����������� ���������� �������,
//		��������� �� ������������ ����� ��������� ������ � MFC
//		DLL.
//
//		� ����������� ��������� MFC 33 � 58 ���������� �����
//		��������� ��������.
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


// �������� CMyDLLApp

CMyDLLApp::CMyDLLApp()
{
	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}


// ������������ ������ CMyDLLApp

CMyDLLApp theApp;


// ������������� CMyDLLApp

BOOL CMyDLLApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
