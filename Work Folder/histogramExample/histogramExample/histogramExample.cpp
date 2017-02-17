// histogramExample.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <vector>
#include <ctime>


void fitBins(std::vector<double> vals, std::vector<int> &bins, double dX, double T)
{
	for (int i = 0; i < vals.size(); i++)
	{
		int idx = 0;
		double x = dX;
		while (x < T + dX)
		{
			if (vals[i] < x)
			{
				bins[idx] += 1;
				break;
			}
			x += dX;
			idx += 1;
		}
	}
}


int main()
{
	std::mt19937 gen(time(NULL));
	std::uniform_real_distribution<double> dist(0.0, 10.0);

	std::vector<double> values;

	for (int i = 0; i < 1000; i++)
	{
		values.push_back(dist(gen));
	}


	return 0;
}
