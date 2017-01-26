// writeFile.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <random>


int main()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::normal_distribution<double> dist(0, 1);

	std::ofstream myFile("values.csv");

	for (int i = 0; i < 1000; i++)
	{
		myFile << dist(gen) << "," << dist(gen) << "," << dist(gen) << "\n";
	}

	myFile.close();

    return 0;
}

