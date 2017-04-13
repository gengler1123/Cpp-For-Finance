// tryCatch_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		throw 20;
	}
	catch (int e)
	{
		std::cout << "An exception occured, numbered " << e << std::endl;
	}
	return 0;
}

