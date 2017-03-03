// MonteCarloClassStructure.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

#include "simulation.hpp"



int main()
{
	std::mt19937 gen(time(NULL));

	unsigned int Trials = 100000;
	unsigned int count = 0;
	for (int i = 0; i < Trials; i++)
	{
		if (i % 1000 == 0)
		{
			std::cout << i << std::endl;
		}
		SingleSimulation S(10, .2, gen);
		if (S.valueSTATE())
		{
			count++;
		}
	}

	std::cout << "The probability is " << double(count) / double(Trials) << std::endl;


	return 0;
}

