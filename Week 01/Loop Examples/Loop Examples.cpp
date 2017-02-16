// Example01.cpp : Defines the entry point for the console application.
//

#include <iostream>


int main()
{

	std::cout << "For Loop" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}

	std::cout << "While Loop" << std::endl;

	int i = 0;
	while (i < 10)
	{
		std::cout << i << std::endl;
		i++;
	}

	std::cout << "Do While Loop" << std::endl;

	i = 0;
	
	do
	{
		std::cout << i << std::endl;
		i++;
	} while (i < 10);

	std::cout << "Difference Between While and Do-While Loops, we set i = 10." << std::endl;
	std::cout << "While Loop" << std::endl;
	i = 10;
	while (i < 10)
	{
		std::cout << i << std::endl;
		i++;
	}
	std::cout << "Do-While Loop" << std::endl;
	i = 10;
	do
	{
		std::cout << i << std::endl;
		i++;
	} while (i < 10);


	return 0;
}

