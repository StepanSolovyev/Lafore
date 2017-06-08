// EMPL_IO.cpp: определяет точку входа для консольного приложения.
//
// Файловый ввод/вывод объектов employee
// Поддержка объектов неодинаковых размеров
#include <fstream>      // для потоковых файловых функций
#include <iostream>
#include <ostream>
#include <istream>
#include <typeinfo>     // для typeid()
#include <process.h>    // для exit()
#include "stdafx.h"
using namespace std;

const int LEN = 32;     // Максимальная длина фамилий
const int MAXEM = 100;  // максимальное число работников

enum employee_type { tmanager, tscientist, tlaborer };
///////////////////////////////////////////////////////////
class employee                   // класс employee 
{
private:
	char name[LEN];           // фамилия работника
	unsigned long number;     // номер работника
	static int n;             // текущее число работников
	static employee* arrap[]; // массив указателей на класс работников
public:
	virtual void getdata()
	{
		cin.ignore(10, '\n');
		cout << "Enter Name: "; cin >> name;

		cout << "Enter namber: ";    cin >> number;
	}
	virtual void putdata()
	{
		cout << "\n  Name: " << name;
		cout << "\n  Namber: " << number;
	}
	virtual employee_type get_type(); // получить тип
	static void add();                // добавить работника
	static void display();            // вывести данные обо всех
	static void read();               // чтение из файла
	static void write();              // запись в файл
};
//---------------------------------------------------------
// статические переменные
int employee::n;                  // текущее число работников
employee* employee::arrap[MAXEM]; // массив указателей на класс работников
								  ///////////////////////////////////////////////////////////
								  // класс manager (менеджеры)
class manager : public employee
{
private:
	char title[LEN];  // титул ("вице-президент" и т. п.)
	double  dues;     // Налоги гольф-клуба
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Enter job title: ";       cin >> title;
		cout << "  Enter nalog: "; cin >> dues;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  Job title: " << title;
		cout << "\n  Nalog of golf club: " << dues;
	}
};
///////////////////////////////////////////////////////////
// класс scientist (ученые)
class scientist : public employee
{
private:
	int pubs;          // число публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Enter amount of publications: "; cin >> pubs;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  Namber of publications: " << pubs;
	}
};

///////////////////////////////////////////////////////////
// класс laborer (рабочие)
class laborer : public employee
{
};
///////////////////////////////////////////////////////////
// добавить работника в список (хранится в ОП)
void employee::add()
{
	char ch;
	cout << "'m' for add manager"
		"\n's' for add scientist"
		"\n'l' for add laborer"
		"\nYour : ";
	cin >> ch;
	switch (ch)
	{         // создать объект указанного типа
	case 'm': arrap[n] = new manager;   break;
	case 's': arrap[n] = new scientist; break;
	case 'l': arrap[n] = new laborer;   break;
	default: cout << "\nUnknown type of emploeer\n"; return;
	}
	arrap[n++]->getdata();  // Получить данные от пользователя
}
//---------------------------------------------------------
// Вывести данные обо всех работниках
void employee::display()
{
	for (int j = 0; j < n; j++)
	{
		cout << (j + 1);            // вывести номер
		switch (arrap[j]->get_type()) // вывести тип 
		{
		case tmanager:   cout << ". Type: manager"; break;
		case tscientist: cout << ". Type: scientist";   break;
		case tlaborer:   cout << ". Type: laborer";  break;
		default: cout << ". Unknown type";
		}
		arrap[j]->putdata();          // Вывод данных
		cout << endl;
	}
}
//---------------------------------------------------------
// Возврат типа объекта
employee_type employee::get_type()
{
	if (typeid(*this) == typeid(manager))
		return tmanager;
	else if (typeid(*this) == typeid(scientist))
		return tscientist;
	else if (typeid(*this) == typeid(laborer))
		return tlaborer;
	else
	{
		cerr << "\nNon correct type of emploeer"; exit(1);
	}
	return tmanager;
}



//---------------------------------------------------------
// Записать все объекты, хранящиеся в памяти, в файл
void employee::write()
{
	int size;
	cout << "Writing " << n << " employeers.\n";
	ofstream ouf;           // открыть ofstream в двоичном виде
	employee_type etype;    // тип каждого объекта employee

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nError open file\n"; return;
	}
	for (int j = 0; j < n; j++)  // Для каждого объекта
	{                           // получить его тип
		etype = arrap[j]->get_type();
		// записать данные в файл
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)       // find its size
		{
		case tmanager:   size = sizeof(manager);   break;
		case tscientist: size = sizeof(scientist); break;
		case tlaborer:   size = sizeof(laborer);   break;
		}      // запись объекта employee в файл   
		ouf.write((char*)(arrap[j]), size);
		if (!ouf)
		{
			cout << "\nWriting to file impossible \n"; return;
		}
	}
}
//---------------------------------------------------------
// чтение всех данных из файла в память
void employee::read()
{
	int size;               // размер объекта employee 
	employee_type etype;    // тип работника
	ifstream inf;           // открыть ifstream в двоичном виде
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\nError open file\n"; return;
	}
	n = 0;                  // В памяти работников нет
	while (true)
	{                       // чтение типа следующего работника
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())   // выход из цикла по EOF
			break;
		if (!inf)        // ошибка чтения типа
		{
			cout << "\nError open type\n"; return;
		}
		switch (etype)
		{                  // создать нового работника
		case tmanager:  // корректного типа
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default: cout << "\nUnknown type in file\n"; return;
		}                     // чтение данных из файла
		inf.read((char*)arrap[n], size);
		if (!inf)              // ошибка, но не EOF
		{
			cout << "\nReading data from file impossible\n"; return;
		}
		n++;                  // счетчик работников увеличить
	}                             // end while
	cout << "Reading " << n << " employeers\n";
}
///////////////////////////////////////////////////////////

int main()
{
	char ch;
	while (true)
	{
		cout << "'a' - Add data by employeer"
			"\n'd' - Display data by all employeers"
			"\n'w' - Write all data in file"
			"\n'r' - Read all data from file"
			"\n'x' - Exit"
			"\nYour choice: ";
		cin >> ch;
		switch (ch)
		{
		case 'a':           // добавить работника
			employee::add(); break;
		case 'd':           // вывести все сведения
			employee::display(); break;
		case 'w':           // запись в файл
			employee::write(); break;
		case 'r':           // чтение всех данных из файла
			employee::read(); break;
		case 'x': exit(0);  // выход
		default: cout << "\nUnknown command";
		}                      // end switch
	}                              // end while
	system("pause");
    return 0;
}

