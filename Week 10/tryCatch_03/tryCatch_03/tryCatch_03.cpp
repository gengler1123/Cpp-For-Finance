// tryCatch_03.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <exception>

double func(int x)
{
	if (x > 4)
	{
		throw "Index too large!";
	}
	double A[4] = { 1, 2, 3, 4 };
	return A[x];
}


int main()
{
	try
	{
		double x = func(5);
		std::cout << x << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}


	return 0;
}
