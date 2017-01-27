#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::setw(10) << "Hello "  << " World" << "!" << std::endl;
	/*
	std::cout << std::setfill('-') << std::setw(50) << std::endl;
	std::cout << std::setprecision(3) << 2.33423432423 << std::endl;
	std::cout << std::setprecision(5) << 2.1 << std::endl;
	std::cout << std::fixed;
	std::cout << std::setprecision(5) << 2.1 << std::endl;
	*/
	double A[2][2];
	A[0][0] = 1.2243;
	A[0][1] = 1.2;
	A[1][0] = 2.3432452345;
	A[1][1] = 3.3424234234352523;

	std::cout << A[0][0] << " " << A[0][1] << std::endl;
	std::cout << A[1][0] << " " << A[1][1] << std::endl;




	return 0;
}