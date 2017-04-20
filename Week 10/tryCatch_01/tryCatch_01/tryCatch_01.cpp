// tryCatch_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
#include <string>

double division(double x, double y)
{
	if (y == 0)
	{
		throw "Division By Zero Not Allowed!";
	}
	return x / y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		division(1.0, 10.0);
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}
	return 0;
}

