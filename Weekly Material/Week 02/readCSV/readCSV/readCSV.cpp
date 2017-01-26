// readCSV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{

	std::ifstream myFile;
	myFile.open("values.csv");
	std::string line;

	while (std::getline(myFile, line))
	{
		std::string value;
		std::stringstream ss(line);
		float x = 0;
		while (std::getline(ss, value, ','))
		{
			std::cout << value << " ";
			x += std::stof(value);
		}
		std::cout << x << " ";
		std::cout << std::endl;
	}

	myFile.close();


    return 0;
}

