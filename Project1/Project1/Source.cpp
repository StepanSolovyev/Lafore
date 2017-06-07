// 
// �������� ����/����� �������� person
#include "header.h"
#include "stdafx.h"
#include <fstream>           // ��� �������� �������
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class person                 // ����� person
{
protected:
	char name[40];           // ��� ��������
	int age;                 // ��� �������
public:
	void getdata(void)       // �������� ������
	{
		cout << "\n  Enter Name: "; cin >> name;
		cout << "  Enter Age: "; cin >> age;
	}
	void showData(void)      // ����� ������

	{
		cout << "\n  Name: " << name;
		cout << "\n  Age: " << age;
	}
	void diskIn(int);        // ������ �� �����
	void diskOut();          // ������ � ����
	static int diskCount();  // ����� ������� � �����
};
//---------------------------------------------------------
void person::diskIn(int pn)  // ������ ������ � �����
							 // ������� pn �� �����
{
	ifstream infile;           // ������� �����
	infile.open("PERSFILE.DAT", ios::binary);  // ������� ���
	infile.seekg(pn * sizeof(person));           // �����
												 // ��������� ���������
	infile.read((char*)this, sizeof(*this));   // ������ ������
											   // �� ����� ��������
}
//---------------------------------------------------------
void person::diskOut()       // ������ � ����� ����� 
{
	ofstream outfile;          // ������� �����
							   // ������� ���
	outfile.open("PERSFILE.DAT", ios::app | ios::binary);
	outfile.write((char*)this, sizeof(*this)); // �������� � ����
}
//---------------------------------------------------------
int person::diskCount()      // ����� ����� � �����
{
	ifstream infile;
	infile.open("PERSFILE.DAT", ios::binary);
	infile.seekg(0, ios::end); // ������� �� ������� �0 ����
							   // �� ����� �����
							   // ��������� ���������� �����
	return (int)infile.tellg() / sizeof(person);
}
///////////////////////////////////////////////////////////
int main()
{
	person p;                  // ������� ������ ������
	char ch;

	do {                        // ���������� ������ �� ����
		cout << "Enter Data of Person: ";
		p.getdata();             // �������� ������
		p.diskOut();             // �������� �� ����
		cout << "Repeat (y/n)? ";
		cin >> ch;
	} while (ch == 'y');      // ���� �� 'n'

	int n = person::diskCount();// ������� ����� � �����?
	cout << "In File " << n << " person(�)\n";
	for (int j = 0; j < n; j++)  // ��� �������
	{
		cout << "\nPerson " << j;
		p.diskIn(j);              // ������� � �����
		p.showData();             // ������� ������

	}
	cout << endl;
	system("pause");
	return 0;
}