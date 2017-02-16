// InClass01.cpp : Defines the entry point for the console application.
//

#include <iostream>


int main(int argc, char* argv[])
{
	std::cout << "Hello World!" << std::endl;

	int x;

	float y;
	double z;

	bool b = true;
	b = false;

	char c = 'c';

	int X[10];
	for (int i = 0; i < 10; i++)
	{
		X[i] = i + 1;
		std::cout << X[i] << std::endl;
	}


	std::cout << "\n" << std::endl;

	const int size = 15;
	float Y[size];

	int i = 0;
	while (i < size)
	{
		Y[i] = float(i) / 2;
		std::cout << Y[i] << std::endl;
		i++;
	}

	std::cout << "\n" << std::endl;

	double Z[size];
	i = 0;
	do
	{
		Z[i] = double(i) * 3.1415;
		std::cout << Z[i] << std::endl;
		i++;

	} while (i < size);

	i = size + 1;

	while (i < size)
	{
		std::cout << "We are in the 'while' loop" << std::endl;
		std::cout << i << std::endl;
	}

	do
	{
		std::cout << "We are in the 'do while' loop" << std::endl;
		std::cout << i << std::endl;
	} while (i < size);


	return 0;
}

