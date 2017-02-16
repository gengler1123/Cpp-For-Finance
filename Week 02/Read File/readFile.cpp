// readFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{

	std::ifstream myFile("ReadMe.txt");

	std::string line;

	while (std::getline(myFile, line))
	{
		std::cout << line << std::endl;
	}

	myFile.close();

    return 0;
}

