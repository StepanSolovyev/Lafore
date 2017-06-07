// 
// Файловый ввод/вывод объектов person
#include "header.h"
#include "stdafx.h"
#include <fstream>           // Для файловых потоков
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class person                 // класс person
{
protected:
	char name[40];           // имя человека
	int age;                 // его возраст
public:
	void getdata(void)       // получить данные
	{
		cout << "\n  Enter Name: "; cin >> name;
		cout << "  Enter Age: "; cin >> age;
	}
	void showData(void)      // Вывод данных

	{
		cout << "\n  Name: " << name;
		cout << "\n  Age: " << age;
	}
	void diskIn(int);        // чтение из файла
	void diskOut();          // запись в файл
	static int diskCount();  // Число человек в файле
};
//---------------------------------------------------------
void person::diskIn(int pn)  // Чтение данных о числе
							 // человек pn из файла
{
	ifstream infile;           // создать поток
	infile.open("PERSFILE.DAT", ios::binary);  // открыть его
	infile.seekg(pn * sizeof(person));           // сдвиг
												 // файлового указателя
	infile.read((char*)this, sizeof(*this));   // чтение данных
											   // об одном человеке
}
//---------------------------------------------------------
void person::diskOut()       // запись в конец файла 
{
	ofstream outfile;          // создать поток
							   // открыть его
	outfile.open("PERSFILE.DAT", ios::app | ios::binary);
	outfile.write((char*)this, sizeof(*this)); // записать в него
}
//---------------------------------------------------------
int person::diskCount()      // число людей в файле
{
	ifstream infile;
	infile.open("PERSFILE.DAT", ios::binary);
	infile.seekg(0, ios::end); // перейти на позицию «0 байт
							   // от конца файла»
							   // вычислить количество людей
	return (int)infile.tellg() / sizeof(person);
}
///////////////////////////////////////////////////////////
int main()
{
	person p;                  // создать пустую запись
	char ch;

	do {                        // сохранение данных на диск
		cout << "Enter Data of Person: ";
		p.getdata();             // Получить данные
		p.diskOut();             // записать на диск
		cout << "Repeat (y/n)? ";
		cin >> ch;
	} while (ch == 'y');      // цикл до 'n'

	int n = person::diskCount();// сколько людей в файле?
	cout << "In File " << n << " person(а)\n";
	for (int j = 0; j < n; j++)  // для каждого
	{
		cout << "\nPerson " << j;
		p.diskIn(j);              // считать с диска
		p.showData();             // вывести данные

	}
	cout << endl;
	system("pause");
	return 0;
}