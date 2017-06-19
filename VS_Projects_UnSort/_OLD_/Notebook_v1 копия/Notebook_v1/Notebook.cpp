#include "Notebook.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
Notebook::Notebook()
{
	cout << "Constructor is working" << endl;
	pFName = new char[l_FName + 1];
	pLName = new char[l_LName + 1];
	pPhone = new char[l_Phone+1];
}
Notebook::~Notebook()
{
	cout << "Destructor is working" << endl;
	delete [] pFName;
	delete [] pLName;
	delete [] pPhone;
}

void Notebook::SetFName(const char* fromBuf) {
	pFName[l_FName] = 0;
	strncpy(pFName,fromBuf,l_FName);
	
}

void Notebook::SetLName(const char* fromBuf) {
	
	pLName[l_LName] = 0;
strncpy(pLName,fromBuf,l_LName);
}

void Notebook::SetPhone(const char* fromBuf) {
	//phone = atoi(fromBuf + l_Phone);
	
	pPhone[l_Phone] = 0;strncpy(pPhone,fromBuf,l_Phone);
}

void Notebook::SetAddress(const char* fromBuf) {
	strncpy(pAddress,fromBuf,l_Address);
	pAddress[l_Address] = 0;
}

void Notebook::Print() const
{
	cout << pFName << pLName  << pPhone << endl;
}