// Export.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Export.h"
#include <stdexcept>

using namespace std;

namespace LandLord
{
	void tenantInputScreen::getTenant()   // получение данных о
	{	// жильцах
		
		getaLine(tName);
		
		cin >> aptNo;
		cin.ignore(80, '\n');               // создать жильца
		tenant* ptrTenant = new tenant(tName, aptNo);
		ptrTenantList->insertTenant(ptrTenant); // занести в
												// список жильцов
		
	

												
												
	////////////////////////////
	 double  MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}

	 double  MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}

	 double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}

	 double MyMathFuncs::Divide(double a, double b)
	{
		if (b == 0)
		{
			throw invalid_argument("b cannot be zero!");
		}

		return a / b;
	}
}