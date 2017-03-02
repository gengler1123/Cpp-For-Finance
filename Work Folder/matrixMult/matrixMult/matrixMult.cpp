// matrixMult.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <iomanip>

void matrixMultiply(
	float **A, int ar, int ac,
	float **B, int br, int bc,
	float **C)
{

	/* Include Checks Here */
	if (ac != br)
	{
		std::cout << "Size Problem" << std::endl;
		return;
	}
	/* Initialize **C */

	/* Carry out Multiplication */

	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			for (int k = 0; k < ac; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


void matrixTranspose(
	float **A, int r, int c,
	float **T)
{
	float hold;
	for (int i = 0; i < r; i++)
	{
		for (int j = i+1; j < c; j++)
		{
			T[i][j] = A[j][i];
		}
	}
}


float grad(float x)
{
	return x*(1 - x);
}


void calculateCost(
	float *layer, int r,
	float *label,
	float *cost)
{
	for (int i = 0; i < r; i++)
	{
		cost[i] = pow((layer[i] - label[i]),2);
	}
}


void costGradient(
	float *layer, int r,
	float *gradient)
{
	for (int i = 0; i < r; i++)
	{
		gradient[i] = grad(layer[i]);
	}
}


void calculateDelta(
	float *delta, int r,
	float *cost, float *gradient)
{
	for (int i = 0; i < r; i++)
	{
		delta[i] = cost[i] * gradient[i];
	}
}


void calculateWeightDelta(
	float *delta, int r, int c,
	float *layer,
	float **WeightDelta)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			WeightDelta[i][j] = layer[i] * delta[j];
		}
	}
}

void updateWeights(
	float **Weights, int r, int c,
	float **WeightDelta)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			Weights[i][j] += WeightDelta[i][j];
		}
	}
}


void printMatrix(
	float **Matrix, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << std::right << std::setw(10) << std::setprecision(2) << Matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int main()
{
	float *input = new float[5];

	float **W = new float*[5];
	float **WT = new float*[5];
	for (int i = 0; i < 5; i++)
	{
		W[i] = new float[5];
		WT[i] = new float[5];
	}

	

	std::mt19937 gen(time(NULL));
	std::uniform_real_distribution<float> dist(-1.0, 1.0);

	float *output = new float[5];
	float *label = new float[5];
	for (int i = 0; i < 5; i++)
	{
		output[i] = 0;
		input[i] = dist(gen);
		label[i] = dist(gen);
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			W[i][j] = .2 * dist(gen);
		}
	}

	matrixTranspose(W, 5, 5, WT);

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				output[j] += input[k] * W[k][j];
			}
		}
	}


	for (int i = 0; i < 5; i++)
	{
		std::cout << output[i] << std::endl;
	}

	float *cost = new float[5];
	float *gradient = new float[5];

	calculateCost(output, 5, label, cost);

	costGradient(cost, 5, gradient);

	float *delta = new float[5];


	calculateDelta(delta, 5, cost, gradient);

	float **WeightD = new float*[5];
	for (int i = 0; i < 5; i++)
	{
		WeightD[i] = new float[5];
	}

	calculateWeightDelta(delta, 5, 5, input, WeightD);

	std::cout << "\nOriginal Weight Matrix:\n" << std::endl;
	printMatrix(W, 5, 5);

	std::cout << "\n" << std::endl;
	std::cout << "Matrix Change:\n" << std::endl;
	printMatrix(WeightD, 5, 5);

	updateWeights(W, 5, 5, WeightD);
	std::cout << "\n" << std::endl;
	printMatrix(W, 5, 5);




	delete[] input; delete[] output; delete[] label; delete[] cost; delete[] gradient; delete[] delta;
	for (int i = 0; i < 5; i++)
	{
		delete[] W[i];
		delete[] WeightD[i];
		delete[] WT[i];
	}
	delete[] W;
	delete[] WeightD;
	delete[] WT;

    return 0;
}

