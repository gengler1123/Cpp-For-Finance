// VectorIterators.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>


int main()
{
	std::vector<float> V;

	for (int i = 0; i < 10; i++)
	{
		V.push_back(i*3.5);
		//std::cout << V[i] << std::endl;
	}

	std::vector<float>::iterator it;

	for (it = V.begin(); it != V.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "============" << std::endl;

	for (it = V.begin(); it != V.end(); ++it)
	{
		if (*it == 7.0)
		{
			std::cout << *it << std::endl;
			it = V.erase(it);
			std::cout << *it << std::endl;
		}
	}




	return 0;
}

