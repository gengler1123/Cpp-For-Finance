// CppPython01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <random>
#include <ctime>
#include <iostream>

int main(int argc, char **argv)
{

	std::mt19937 gen(time(NULL));
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	std::cout << argc << std::endl;
	
	std::ofstream myFile;
	if (argc == 1)
	{
		myFile.open("dataGen.csv");
	}
	else
	{
		myFile.open(argv[1]);
	}

	for (int i = 0; i < 100; i++)
	{
		myFile << dist(gen) << "," << dist(gen) << "\n";
	}

	myFile.close();

    return 0;
}

