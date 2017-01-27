// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include <fstream>


double dx(double x)
{
	return -x;
}


double eulerTimestep(
	double x,
	double dt)
{
	return x + dx(x)*dt;
}

int main()
{
	int numTimesteps = 4*256;
	double dt = 1/256.0;

	double *arr;
	arr = new double[numTimesteps];
	arr[0] = 5;

	std::ofstream myFile("Results.csv");

	for (int i = 1; i < numTimesteps; i++)
	{
		arr[i] = eulerTimestep(arr[i - 1], dt);
		myFile << i*dt << "," << arr[i] << "\n";
	}
	myFile.close();

	delete[] arr;

}