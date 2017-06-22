// tempfind.cpp: определяет точку входа для консольного приложения.
//Шаблон функции поиска в массиве

#include "stdafx.h"

template <class atype>
int find(atype* array, atype value, int size)
{
	for (int j = 0; j < size; j++)
		if (array[j] == value)
			return j;
	return -1;
}
//---------------------------------------------------------
char chrArr[] = { 1, 3, 5, 9, 11, 13 }; // массив
char ch = 5;                              // искомое значение
int intArr[] = { 1, 3, 5, 9, 11, 13 };
int in = 6;
long lonArr[] = { 1L, 3L, 5L, 9L, 11L, 13L };
long lo = 11L;
double  dubArr[] = { 1.0, 3.0, 5.0, 9.0, 11.0, 13.0 };
double  db = 4.0;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n 5 в chrArray: индекс =" << find(chrArr, ch, 6);
	cout << "\n 6 в intArray: индекс =" << find(intArr, in, 6);
 	cout << "\n11 в lonArray: индекс =" << find(lonArr, lo, 6);
	cout << "\n 4 в dubArray: индекс =" << find(dubArr, db, 6);
	cout << endl;
	system("pause");
    return 0;
}

