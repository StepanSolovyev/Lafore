// temstak2.cpp: определяет точку входа для консольного приложения.
// реализует стековый класс в виде шаблона
// методы определяются вне класса



#include "stdafx.h"


const int MAX = 100;
/////////////////////////////////////////////////////////////
template <class Type>
class Stack
{
private:
	Type st[MAX];         // стек - массив любого типа
	int top;              // индекс вершины стека
public:
	Stack();              // конструктор
	void push(Type var);  // занести число в стек
	Type pop();           // взять число из стека
};
/////////////////////////////////////////////////////////////
template<class Type>
Stack<Type>::Stack()      // конструктор
{
	top = -1;
}
//-----------------------------------------------------------
template<class Type>
void Stack<Type>::push(Type var) // положить число в стек
{
	st[++top] = var;
}
//-----------------------------------------------------------
template<class Type>
Type Stack<Type>::pop()          // взять число из стека
{
	return st[top--];
}
//-----------------------------------------------------------

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Stack<float> s1;               // s1 - объект класса Stack<float>

	s1.push(1111.1F);              // занести 3 float, вытолкнуть 3 float

	s1.push(2222.2F);
	s1.push(3333.3F);
	cout << "1: " << s1.pop() << endl;
	cout << "2: " << s1.pop() << endl;
	cout << "3: " << s1.pop() << endl;

	Stack<long> s2;         // s2 - объект класса Stack<long>

	s2.push(123123123L);    // занести 3 long, вытолкнуть 3 long
	s2.push(234234234L);
	s2.push(345345345L);
	cout << "1: " << s2.pop() << endl;
	cout << "2: " << s2.pop() << endl;
	cout << "3: " << s2.pop() << endl;
	system("pause");
    return 0;
}

