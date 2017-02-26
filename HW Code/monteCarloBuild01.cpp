// monteCarloBuild01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <ctime>
#include <vector>

#define N 10
#define R .4

class Point
{
public:
	double x;
	double y;
};

int main()
{

	std::mt19937 gen(time(NULL));
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	std::vector<Point> Points;

	for (int i = 0; i < N; i++)
	{
		Point p;
		p.x = dist(gen);
		p.y = dist(gen);
		Points.push_back(p);
	}

	std::vector<Point> Jumpable;
	Point S;
	S.x = 0;
	S.y = 0;
	Jumpable.push_back(S);

	Point E;
	E.x = 1;
	E.y = 1;


	bool RUN = true;

	while (RUN)
	{
		RUN = false;

		std::vector<Point> HOLD;

		for (int j = 0; j < Jumpable.size(); j++)
		{
			double exdist = pow(Points[j].x - E.x, 2);
			double eydist = pow(Points[j].y - E.y, 2);
			if (sqrt(exdist + eydist) < R)
			{
				/* End Conditions */
				std::cout << "It is Jumpable!" << std::endl;
				return 0;
			}

			for (int i = 0; i < Points.size(); i++)
			{
				

				double xdist = pow(Points[i].x - Jumpable[j].x, 2);
				double ydist = pow(Points[i].y - Jumpable[j].y, 2);
				if (sqrt(xdist + ydist) < R)
				{
					RUN = true;
					HOLD.push_back(Points[i]);

				}
			}
		}

		/* Add all from HOLD to Jumpable */
		for (int i = 0; i < HOLD.size(); i++)
		{
			Jumpable.push_back(HOLD[i]);
		}

		/* Remove All from HOLD from Points */
		
	}
	std::cout << "This is not jumpable!" << std::endl;
	return 0;
}