// // englio2.cpp
// ������������� << � >> � �������
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;
class Distance            // ����� ���������� ����������
{
private:
	int feet;
	float inches;
public:
	// ����������� (��� ����������)
	Distance() : feet(0), inches(0.0)
	{  }
	// ����������� (2-���)
	Distance(int ft, float in) : feet(ft), inches(in)
	{  }
	friend istream& operator >> (istream& s, Distance& d);
	friend ostream& operator<<(ostream& s, Distance& d);
};
//---------------------------------------------------------
// �������� ������ �� ����� ��� � ����������
// ��� ('), (-) � (") � ������� �������������� >>
istream& operator >> (istream& s, Distance& d)
{
	char dummy;
	s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
	return s;
}
//---------------------------------------------------------
// ������� ������ ���� Distance � ���� ��� �� ����� ������������� <<
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
	ofstream ofile;         // ������� � �������
	ofile.open("DIST.DAT"); // �������� �����

	do {
		cout << "\n������� ����������: ";
		cin >> dist1;        // �������� ������ �� ������������
		ofile << dist1;      // �������� �� � �������� �����
		cout << "���������� (�/�)? ";
		cin >> ch;
	} while (ch != '�');
	ofile.close();          // ������� �������� �����

	ifstream ifile;         // ������� � ������� 
	ifile.open("DIST.DAT"); // ������� �����

	cout << "\n���������� �����:\n";
	while (true)
	{
		ifile >> dist1;       // ������ ������ �� ������
		if (ifile.eof())       // ����� �� EOF
			break;
		cout << "���������� = " << dist1 << endl; // �����
												  // ����������
	}
	system("pause");
    return 0;
}

