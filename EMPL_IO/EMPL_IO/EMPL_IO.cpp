// EMPL_IO.cpp: ���������� ����� ����� ��� ����������� ����������.
//
// �������� ����/����� �������� employee
// ��������� �������� ������������ ��������
#include <fstream>      // ��� ��������� �������� �������
#include <iostream>
#include <ostream>
#include <istream>
#include <typeinfo>     // ��� typeid()
#include <process.h>    // ��� exit()
#include "stdafx.h"
using namespace std;

const int LEN = 32;     // ������������ ����� �������
const int MAXEM = 100;  // ������������ ����� ����������

enum employee_type { tmanager, tscientist, tlaborer };
///////////////////////////////////////////////////////////
class employee                   // ����� employee 
{
private:
	char name[LEN];           // ������� ���������
	unsigned long number;     // ����� ���������
	static int n;             // ������� ����� ����������
	static employee* arrap[]; // ������ ���������� �� ����� ����������
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
	virtual employee_type get_type(); // �������� ���
	static void add();                // �������� ���������
	static void display();            // ������� ������ ��� ����
	static void read();               // ������ �� �����
	static void write();              // ������ � ����
};
//---------------------------------------------------------
// ����������� ����������
int employee::n;                  // ������� ����� ����������
employee* employee::arrap[MAXEM]; // ������ ���������� �� ����� ����������
								  ///////////////////////////////////////////////////////////
								  // ����� manager (���������)
class manager : public employee
{
private:
	char title[LEN];  // ����� ("����-���������" � �. �.)
	double  dues;     // ������ �����-�����
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
// ����� scientist (������)
class scientist : public employee
{
private:
	int pubs;          // ����� ����������
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
// ����� laborer (�������)
class laborer : public employee
{
};
///////////////////////////////////////////////////////////
// �������� ��������� � ������ (�������� � ��)
void employee::add()
{
	char ch;
	cout << "'m' for add manager"
		"\n's' for add scientist"
		"\n'l' for add laborer"
		"\nYour : ";
	cin >> ch;
	switch (ch)
	{         // ������� ������ ���������� ����
	case 'm': arrap[n] = new manager;   break;
	case 's': arrap[n] = new scientist; break;
	case 'l': arrap[n] = new laborer;   break;
	default: cout << "\nUnknown type of emploeer\n"; return;
	}
	arrap[n++]->getdata();  // �������� ������ �� ������������
}
//---------------------------------------------------------
// ������� ������ ��� ���� ����������
void employee::display()
{
	for (int j = 0; j < n; j++)
	{
		cout << (j + 1);            // ������� �����
		switch (arrap[j]->get_type()) // ������� ��� 
		{
		case tmanager:   cout << ". Type: manager"; break;
		case tscientist: cout << ". Type: scientist";   break;
		case tlaborer:   cout << ". Type: laborer";  break;
		default: cout << ". Unknown type";
		}
		arrap[j]->putdata();          // ����� ������
		cout << endl;
	}
}
//---------------------------------------------------------
// ������� ���� �������
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
// �������� ��� �������, ���������� � ������, � ����
void employee::write()
{
	int size;
	cout << "Writing " << n << " employeers.\n";
	ofstream ouf;           // ������� ofstream � �������� ����
	employee_type etype;    // ��� ������� ������� employee

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nError open file\n"; return;
	}
	for (int j = 0; j < n; j++)  // ��� ������� �������
	{                           // �������� ��� ���
		etype = arrap[j]->get_type();
		// �������� ������ � ����
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)       // find its size
		{
		case tmanager:   size = sizeof(manager);   break;
		case tscientist: size = sizeof(scientist); break;
		case tlaborer:   size = sizeof(laborer);   break;
		}      // ������ ������� employee � ����   
		ouf.write((char*)(arrap[j]), size);
		if (!ouf)
		{
			cout << "\nWriting to file impossible \n"; return;
		}
	}
}
//---------------------------------------------------------
// ������ ���� ������ �� ����� � ������
void employee::read()
{
	int size;               // ������ ������� employee 
	employee_type etype;    // ��� ���������
	ifstream inf;           // ������� ifstream � �������� ����
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\nError open file\n"; return;
	}
	n = 0;                  // � ������ ���������� ���
	while (true)
	{                       // ������ ���� ���������� ���������
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())   // ����� �� ����� �� EOF
			break;
		if (!inf)        // ������ ������ ����
		{
			cout << "\nError open type\n"; return;
		}
		switch (etype)
		{                  // ������� ������ ���������
		case tmanager:  // ����������� ����
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
		}                     // ������ ������ �� �����
		inf.read((char*)arrap[n], size);
		if (!inf)              // ������, �� �� EOF
		{
			cout << "\nReading data from file impossible\n"; return;
		}
		n++;                  // ������� ���������� ���������
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
		case 'a':           // �������� ���������
			employee::add(); break;
		case 'd':           // ������� ��� ��������
			employee::display(); break;
		case 'w':           // ������ � ����
			employee::write(); break;
		case 'r':           // ������ ���� ������ �� �����
			employee::read(); break;
		case 'x': exit(0);  // �����
		default: cout << "\nUnknown command";
		}                      // end switch
	}                              // end while
	system("pause");
    return 0;
}

