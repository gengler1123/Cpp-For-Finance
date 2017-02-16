// InClass02.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
/*

Compute the polynomial x^3 + 2*x^2 + 3

*/


double polynom(double x)
{
	return pow(x, 3) + 2 * pow(x, 2) + 3;
}



int main()
{
	double x = 3;

	std::cout << "x^3 + 2x^2 + 3 = " << polynom(x) << std::endl;

	double X[10];
	X[0] = 0;

	for (int i = 0; i < 10-1; i++)
	{
		X[i + 1] = polynom(X[i]);
		std::cout << X[i + 1] << std::endl;
	}


	return 0;
}

