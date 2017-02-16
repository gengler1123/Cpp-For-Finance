// Introduction to Pseudo Random Numbers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <ctime>

int main()
{
	std::default_random_engine rd;
	std::mt19937 gen(rd());


	std::uniform_real_distribution<double> uniDist(0.0, 1.0);
	std::normal_distribution<double> stdNorm(0.0, 1.0);
	std::exponential_distribution<double> expDist(1.0);

	std::cout << "Single Examples:\n" << std::endl;
	std::cout << "From Uniform Distribution:     " << uniDist(gen) << std::endl;
	std::cout << "From Normal Distribution:      " << stdNorm(gen) << std::endl;
	std::cout << "From Exponential Distribution: " << expDist(gen) << std::endl;


	std::cout << "\n\n" << std::endl;

	std::cout << "Calculating Basic Statistics\n" << std::endl;
	double Uni[1000], Norm[1000], Expo[1000];
	double uni = 0, norm = 0, expo = 0;
	for (int i = 0; i < 1000; i++)
	{
		Uni[i] = uniDist(gen);
		uni += Uni[i];

		Norm[i] = stdNorm(gen);
		norm += Norm[i];

		Expo[i] = expDist(gen);
		expo += Expo[i];
	}

	uni /= 1000.0;
	norm /= 1000.0;
	expo /= 1000.0;

	std::cout << "Sample Mean Uniform     : " << uni << std::endl;
	std::cout << "Sample Mean Normal      : " << norm << std::endl;
	std::cout << "Sample Mean Exponential : " << expo << std::endl;

	double Vu = 0, Vn = 0, Ve = 0;

	for (int i = 0; i < 1000; i++)
	{
		Vu += pow((uni - Uni[i]), 2);
		Vn += pow((norm - Norm[i]), 2);
		Ve += pow((expo - Expo[i]), 2);
	}

	Vu /= 1000.0;
	Vn /= 1000.0;
	Ve /= 1000.0;


	std::cout << "Sample Variance Uniform     : " << Vu << std::endl;
	std::cout << "Sample Variance Normal      : " << Vn << std::endl;
	std::cout << "Sample Variance Exponential : " << Ve << std::endl;

	return 0;
}