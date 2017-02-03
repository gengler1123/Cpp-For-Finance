// referenceExample.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

double dx(double x)
{
	return x*x - 9;
}

void eulerTimestep(
	double dt,
	std::vector<double> &vec)
{
	vec.push_back( vec.back() + dx(vec.back())* dt);
}


double f(double x, double y)
{
	return -x + (x*x + y*y);
}

double g(double x, double y)
{
	return -y - (x*x + y*y);
}

void EULER(
	double dt,
	std::vector<std::vector<double>> &vec)
{

	std::vector<double> hold;
	hold.push_back(vec.back()[0] + f(vec.back()[0], vec.back()[1])*dt);
	hold.push_back(vec.back()[1] + g(vec.back()[0], vec.back()[1])*dt);
	vec.push_back(hold);
}

int main()
{
	/*
	std::vector<double> v;
	v.push_back(2.4);
	for (int i = 0; i < 100; i++)
	{
		eulerTimestep(.01, v);
	}

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}


	std::vector<std::vector<double>> Vec;

	std::vector<double> v1;
	v1.push_back(2.3);
	v1.push_back(5.3);
	Vec.push_back(v1);

	std::cout << Vec[0][0] << std::endl;
	*/

	int guest = 5;
	while (++guest < 6)
	{
		std::cout << guest << std::endl;
	}

	return 0;
}