#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__


#include <string>
#include <random>
#include <ctime>
#include <cmath>

#include "readdata.hpp"

class Network
{
private:
	InputData data;
	int inputSize, hiddenSize, outputSize;
	float *input, *hidden, *output;
	float **Syn0, **Syn1;

	void genWeights(float **Syn, int m, int n);
protected:

public:
	Network(std::string PATH) { data.readData(PATH); inputSize = 2; hiddenSize = 20; outputSize = 3; };
	Network(
		std::string PATH,
		int inputSize_,
		int hiddenSize_,
		int outputSize_);
};


Network::Network(
	std::string PATH,
	int inputSize_,
	int hiddenSize_,
	int outputSize_)
{
	inputSize = inputSize_;
	hiddenSize = hiddenSize_;
	outputSize = outputSize_;
	data.readData(PATH);
}


void Network::genWeights(float **Syn, int m, int n)
{
	std::mt19937 gen(time(NULL));
	std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Syn[i][j] = sqrt(float(hiddenSize))*dist(gen);
		}
	}
}














#endif