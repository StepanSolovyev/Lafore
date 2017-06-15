// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<TCHAR.H>
#include <iostream>
#include <Windows.h>
#include <string.h>  
//#include <locale.h>
using namespace std;

// TCHAR strsort[16];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TCHAR str[16] = "Иришка-красотка";
	wcout << str << endl;

	wcout << "Длина строки :" << strlen(str) << endl;

	for (int j = strlen(str); j >= 0; j--)
	     wcout << str[j];
	wcout << endl;
	
	system("pause");
    return 0;
}
