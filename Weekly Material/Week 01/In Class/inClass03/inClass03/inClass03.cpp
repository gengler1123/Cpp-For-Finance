// inClass03.cpp : Defines the entry point for the console application.
//

#include <iostream>


int main()
{
	int x = 10;
	std::cout << "x = " << x << std::endl;

	int *ptr;
	ptr = &x;

	std::cout << "ptr = " <<  ptr << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;

	*ptr = 20;

	std::cout << "*ptr = " << *ptr << std::endl;
	std::cout << "x = " << x << std::endl;


	std::cout << "Dynamic Arrays! " << std::endl;

	/* Create a dynamic array of integers. */
	int *h_arr;
	int size = 100;
	h_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		h_arr[i] = i + 1;
		//std::cout << h_arr[i] << std::endl;
	}

	ptr = h_arr;
	std::cout << "*ptr = " << *ptr << std::endl;
	ptr++;
	std::cout << "*ptr = " << *ptr << std::endl;
	ptr += 3;
	std::cout << "*ptr = " << *ptr << std::endl;
	

	delete[] h_arr;

	return 0;
}

