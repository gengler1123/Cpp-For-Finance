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

	SingleSimulation S(
		10, 
		.2, 
		gen);

	std::cout << "The Value Is " << std::endl;
	S.printValue();

	return 0;
}

