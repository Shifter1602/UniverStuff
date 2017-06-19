#define UNICODE
#ifdef UNICODE
#define _UNICODE
#endif
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

using namespace std;


void main()
{
	HANDLE hFile;
	PTCHAR FileName = _T("MyFile.txt");
	PTCHAR TextString = _T("Hello World!!");
	DWORD iWrite, StringLength = lstrlen(TextString);

	_tprintf(_T("There are %ld symbols in text string %s\n"), StringLength, TextString);
	
	hFile = CreateFile(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | 0, NULL);

	iWrite = StringLength;
#ifdef UNICODE
	iWrite = 2*StringLength;
#endif

	WriteFile(hFile, TextString, iWrite, &iWrite, NULL);
	printf("%d bytes sre written to file\n", iWrite);
	CloseHandle(hFile);

	//cout<<TextString;
	_tprintf(_T("%s"),TextString);
	getch();
}
