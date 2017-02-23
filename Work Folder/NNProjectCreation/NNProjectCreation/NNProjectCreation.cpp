// NNProjectCreation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

// First Be Able To Read Data
#include "readdata.hpp"

// Intialize Network
#include "network.hpp"


int main()
{
	std::vector<float*> v;
	float *ptr;
	v.push_back(ptr);
	v.push_back(new float[100]);

	for (int i = 0; i < 100; i++)
	{
		v[1][i] = i + 1;
	}

	v[0] = v[1];

	std::cout << *(v[0]) << std::endl;

	std::cout << *(v[0] + 3) << std::endl;

	delete[] v[1];
    return 0;
}

