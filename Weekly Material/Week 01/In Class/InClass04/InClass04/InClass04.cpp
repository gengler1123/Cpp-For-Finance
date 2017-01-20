// InClass04.cpp : Defines the entry point for the console application.
//

#include <iostream>


int DoSomething(int x)
{
	int NewVariable = 4;
	NewVariable += x;
	x += 3;
	return x;
}

void ChangeSomething(int &x)
{
	x += 1;
}


int main()
{

	int x = 4;
	std::cout << DoSomething(x) << std::endl;

	std::cout << "x = " << x << std::endl;

	ChangeSomething(x);

	std::cout << "x = " << x << std::endl;

	int y;
	
	std::cout << "Input a value for y: ";
	std::cin >> y;
	std::cout << std::endl;

	std::cout << "y = " << y << std::endl;
	
	bool badValue = true;

	int z;
	/*
	while (badValue)
	{

		std::cout << "Input a positive integer: ";
		std::cin >> z;

		
		if (z > 0)
		{
			std::cout << "That is a correct value!" << std::endl;
			badValue = false;
		}
		else
		{
			std::cout << "Wrong value, enter a positive integer!" << std::endl;
		}
	}
	*/
	


	return 0;
}

