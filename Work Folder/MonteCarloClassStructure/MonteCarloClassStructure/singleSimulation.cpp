#include "singleSimulation.hpp"

#include <iostream>


SingleSimulation::SingleSimulation(
	int N_, 
	double R_,
	std::mt19937 &gen)
{
	N = N_;
	R = R_;
	std::vector<Point> Points;

	std::uniform_real_distribution<double> dist(0.0, 1.0);
	double x, y;

	for (int i = 0; i < N; i++)
	{
		x = dist(gen);
		y = dist(gen);
		Point P;
		P.x = x;
		P.y = y;
		Points.push_back(P);
	}

	std::vector<Point> toBe,checked, next;
	std::vector<Point>::iterator it;
	std::vector<Point>::iterator jt;

	Point O; Point E;
	O.x = 0.0; O.y = 0.0;
	E.x = 1.0; E.y = 1.0;

	toBe.push_back(O);

	std::cout << "HERE" << std::endl;

	std::vector<std::vector<Point>::iterator> HELD;

	while (toBe.size() != 0)
	{
		next.clear();
		for (it = toBe.begin(); it != toBe.end(); ++it)
		{
			std::cout << "Here" << std::endl;
			if (distCheck(*it, E))
			{
				STATE = true;
				return;
			}
			std::cout << "HERE " << std::endl;
			for (jt = Points.begin(); jt != Points.end();)
			{
				std::cout << (*jt).x << "," << (*jt).y << std::endl;
				if (distCheck(*jt, *it))
				{
					next.push_back(*jt);
					jt = Points.erase(jt);
				}
				else
				{
					jt++;
				}
			}
		}
		
		toBe.clear();
		toBe = next;
	}
	STATE = false;
}


bool SingleSimulation::distCheck(
	Point p,
	Point q)
{
	double x = pow((p.x - q.x), 2);
	double y = pow((p.y - q.y), 2);
	if (x*x + y*y <= R*R)
	{
		return true;
	}
	return false;
}
