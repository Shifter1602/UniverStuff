#include <fstream>
#include <iostream>
#include "conio.h"
#include "Notebook.h"
using namespace std;
const char filename[] = "Notebook1.txt";
const int maxn_record =10;

int GetNumber(int min, int max)
{
	int number = min - 1;
	while (true)
	{
		cin >> number;
		if ((number >= min) && (number <= max) && (cin.peek() == '\n'))
			break;
		else {
			cout << "Повторите ввод (ожидается число от " << min << " до " << max << " ) : " << endl;
			cin.clear();
			while (cin.get() != '\n') {};
		}
	}
	return number;
}

int Read()
{
	ifstream fin(filename);
	if (!fin) {
		cout << "Нет файла " << filename << endl; return 1;
	}
	int i = 0;
	while (fin.getline(buf,l_buf+1)) {
		if (i >= maxn_record) {
			cout << "Слишком длинный файл"<< endl; return 1; }
		note[i].SetFName(buf);
		note[i].SetLName(buf+l_FName);
		note[i].SetPhone(buf+l_FName+l_LName);
		i++;
	}
	fin.close();
	return i;
}

void Print(int i)
{
	for(int j=0;j<i;j++)
	{
		note[j].Print();
	}
}

int main()
{
	setlocale(LC_ALL,"");
	extern Notebook note[maxn_record];
	extern char buf [l_buf + 1];
	extern char LName[l_LName+1];
	extern char FName[l_FName+1];
	extern char Phone[l_Phone+1];

	switch(GetNumber(1,2))
	{
	case 1: Read(); break;
	case 2: Print(Read());break;
	}

	
/*
while(true)
{
	cout << "Введите имя или слово end: ";
	cin >> FName;
	if (0 == strcmp(FName, "end")) break;
	fin<<FName+strlen(FName)<<endl;
}*/

return 0;
}


