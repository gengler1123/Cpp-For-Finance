// workshopEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
struct Point2D
{
	double x;
	double y;
};


double dx(double x, double y);
double dy(double x, double y);


void EulerTimestep(std::vector<Point2D> &V, double dt)
{
	double xh = V.back().x;
	double yh = V.back().y;
	Point2D p;
	p.x = xh + dt * dx(xh, yh);
	p.y = yh + dt * dy(xh, yh);
	V.push_back(p);
}

int _tmain(int argc, _TCHAR* argv[])
{

	std::vector<Point2D> V;

	return 0;
}

