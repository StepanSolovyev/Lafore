// // englio2.cpp
// перегружаемые << и >> с файлами
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;
class Distance            // класс английских расстояний
{
private:
	int feet;
	float inches;
public:
	// конструктор (без аргументов)
	Distance() : feet(0), inches(0.0)
	{  }
	// конструктор (2-арг)
	Distance(int ft, float in) : feet(ft), inches(in)
	{  }
	friend istream& operator >> (istream& s, Distance& d);
	friend ostream& operator<<(ostream& s, Distance& d);
};
//---------------------------------------------------------
// получить данные из файла или с клавиатуры
// для ('), (-) и (") с помощью перегруженного >>
istream& operator >> (istream& s, Distance& d)
{
	char dummy;
	s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
	return s;
}
//---------------------------------------------------------
// послать данные типа Distance в файл или на экран перегруженным <<
ostream& operator<<(ostream& s, Distance& d)
{
	s << d.feet << "\'-" << d.inches << '\"';
	return s;
}

///////////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char ch;
	Distance dist1;
	ofstream ofile;         // создать и открыть
	ofile.open("DIST.DAT"); // выходной поток

	do {
		cout << "\nВведите расстояние: ";
		cin >> dist1;        // получить данные от пользователя
		ofile << dist1;      // записать их в выходной поток
		cout << "Продолжать (д/н)? ";
		cin >> ch;
	} while (ch != 'н');
	ofile.close();          // закрыть выходной поток

	ifstream ifile;         // создать и открыть 
	ifile.open("DIST.DAT"); // входной поток

	cout << "\nСодержимое файла:\n";
	while (true)
	{
		ifile >> dist1;       // чтение данных из потока
		if (ifile.eof())       // выход по EOF
			break;
		cout << "Расстояние = " << dist1 << endl; // вывод
												  // расстояний
	}
	system("pause");
    return 0;
}

