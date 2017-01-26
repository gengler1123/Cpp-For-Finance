// ioManipExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Hello " << std::setw(10) << " World" << "!" << std::endl;
	/*
	std::cout << std::setfill('-') << std::setw(10) << ""<< std::endl;

	std::cout << std::setprecision(3) << 2.33423432423 << std::endl;

	std::cout << std::setprecision(5) << 2.1 << std::endl;

	std::cout << std::fixed;

	std::cout << std::setprecision(5) << 2.1 << std::endl;
	*/
    return 0;
}

