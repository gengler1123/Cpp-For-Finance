// functionPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void func(double (*f)(double), double x)
{
	std::cout << f(x) << std::endl;
}

double g(double x)
{
	return x*x - 3;
}

double h(double x)
{
	return x - 4;
}


double i(double x)
{
	return x*x*x*x;
}


int _tmain(int argc, _TCHAR* argv[])
{
	func(g,3);
	func(h, 3);
	func(i, 3);

	return 0;
}

