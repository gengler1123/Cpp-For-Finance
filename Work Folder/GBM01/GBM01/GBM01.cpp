// GBM01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

void GBM(std::vector<double> &v, double mu, double sigma, int T = 100, double dt = 0.1)
{
	std::mt19937 gen(time(NULL));
	std::normal_distribution<double> dist(0.0, 1.0);

	int TOT = double(T) / dt;
	double dTOT = 1 / double(TOT);
	double hold;
	for (int i = 0; i < TOT; i++)
	{
		hold = v.back() + v.back()*(dTOT * mu + dist(gen)*sqrt(dTOT*sigma));
		v.push_back(hold);
	}
}


void writeToFile(std::vector<double> v, std::string PATH = "singlePath.csv")
{

	std::ofstream myFile(PATH);
	for (int i = 0; i < v.size(); i++)
	{
		myFile << v[i] << std::endl;
	}
	myFile.close();
}


int main()
{
	std::vector<double> traj;
	traj.push_back(1.0);

	GBM(traj, 1.0, .2);

	writeToFile(traj);

	return 0;
}