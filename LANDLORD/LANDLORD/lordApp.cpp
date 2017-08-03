// lordApp.cpp
// файл, поставляемый клиенту.
#include "stdafx.h"
#include "landlord.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	userInterface theUserInterface;

	theUserInterface.interact();
	
	return 0;
}
////////////////////конец файла lordApp.cpp////////////////
