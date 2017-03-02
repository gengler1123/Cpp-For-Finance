#ifndef __SINGLESIMULATION_HPP__
#define __SINGLESIMULATION_HPP__

#include <iostream>
#include <random>
#include <ctime>
#include <vector>

struct Point
{
	double x, y;
};


class SingleSimulation
{
private:
	/* Private Member Variables */
	bool STATE;
	int N;
	double R;
	Point *Points;


	/* Private Member Functions */
	void runFunction();
	bool distCheck(Point p, Point q);


	/* Class Friends */
	friend class Simulation;


public:
	SingleSimulation(
		int N, 
		double R,
		std::mt19937 &gen);
	void printValue(){ std::cout << STATE << std::endl; };
};


#endif