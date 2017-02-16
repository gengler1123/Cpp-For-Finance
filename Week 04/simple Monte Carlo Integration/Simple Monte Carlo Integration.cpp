// Simple Monte Carlo Integration.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

bool regionCheck(double x, double y)
{
	if (x*x + y*y <= 1.0)
	{
		return true;
	}
	return false;
}

int main()
{
	std::mt19937 gen(time(NULL));
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	double x, y;
	unsigned int cnt = 0;
	int N = 1000000;
	for (int i = 0; i < N; i++)
	{
		x = dist(gen);
		y = dist(gen);
		if (regionCheck(x, y))
		{
			cnt += 1;
		}
	}

	double P = 4.0 * double(cnt) / double(N);

	std::cout << "The approximated value is " << P << std::endl;
	std::cout << "The Error of the approximation is " << P - std::_Pi << std::endl;

	return 0;
}