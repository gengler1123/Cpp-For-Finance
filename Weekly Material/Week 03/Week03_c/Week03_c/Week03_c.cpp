// Week03_c.cpp : Defines the entry point for the console application.
//


#include <iostream>

#include "stock.h"


int main()
{
	Stock IBM(
		"International ...",
		"IBM",
		10000,
		132.43);

	std::cout << "The current value is $" << IBM.currentValue() << std::endl;

	return 0;
}

