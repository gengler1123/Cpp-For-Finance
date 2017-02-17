// GBM01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

void GBM(std::vector<double> &v, double mu, double sigma, std::mt19937 &gen, int T = 100, double dt = 0.1)
{
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


void writeAll(std::vector<std::vector<double>> V, std::string PATH = "multiRuns.csv")
{
	std::ofstream myFile(PATH);
	for (int t = 0; t < V[0].size(); t++)
	{
		myFile << V[0][t];
		for (int i = 1; i < V.size(); i++)
		{
			myFile << "," << V[i][t];
		}
		myFile << "\n";
	}
	myFile.close();
}

int main(int argc, char**argv)
{
	double mu = 1.0;
	double sigma = .2;

	if (argc == 3)
	{
		mu = std::stof(argv[1]);
		sigma = std::stof(argv[2]);
	}

	unsigned int N = 100;

	std::mt19937 gen(time(NULL));

	std::vector<std::vector<double>> TRAJ;
	for (int n = 0; n < N; n++)
	{
		std::vector<double> traj;
		traj.push_back(1.0);

		GBM(traj, mu, sigma, gen);
		TRAJ.push_back(traj);
	}

	writeAll(TRAJ);

	return 0;
}