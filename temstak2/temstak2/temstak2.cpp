// temstak2.cpp: ���������� ����� ����� ��� ����������� ����������.
// ��������� �������� ����� � ���� �������
// ������ ������������ ��� ������



#include "stdafx.h"


const int MAX = 100;
/////////////////////////////////////////////////////////////
template <class Type>
class Stack
{
private:
	Type st[MAX];         // ���� - ������ ������ ����
	int top;              // ������ ������� �����
public:
	Stack();              // �����������
	void push(Type var);  // ������� ����� � ����
	Type pop();           // ����� ����� �� �����
};
/////////////////////////////////////////////////////////////
template<class Type>
Stack<Type>::Stack()      // �����������
{
	top = -1;
}
//-----------------------------------------------------------
template<class Type>
void Stack<Type>::push(Type var) // �������� ����� � ����
{
	st[++top] = var;
}
//-----------------------------------------------------------
template<class Type>
Type Stack<Type>::pop()          // ����� ����� �� �����
{
	return st[top--];
}
//-----------------------------------------------------------

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Stack<float> s1;               // s1 - ������ ������ Stack<float>

	s1.push(1111.1F);              // ������� 3 float, ���������� 3 float

	s1.push(2222.2F);
	s1.push(3333.3F);
	cout << "1: " << s1.pop() << endl;
	cout << "2: " << s1.pop() << endl;
	cout << "3: " << s1.pop() << endl;

	Stack<long> s2;         // s2 - ������ ������ Stack<long>

	s2.push(123123123L);    // ������� 3 long, ���������� 3 long
	s2.push(234234234L);
	s2.push(345345345L);
	cout << "1: " << s2.pop() << endl;
	cout << "2: " << s2.pop() << endl;
	cout << "3: " << s2.pop() << endl;
	system("pause");
    return 0;
}

