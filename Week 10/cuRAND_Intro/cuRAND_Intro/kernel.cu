
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <ctime>
#include <iostream>
#include <iomanip>

#include "curand.h"
#include "curand_kernel.h"

__global__ void initializePRG(
	int size,
	unsigned int seed,
	curandState_t *d_states)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i >= size){return;}
	curand_init(
		seed,
		i,
		0,
		&d_states[i]);
}


__global__ void uniformDist(
	int size,
	curandState_t *d_states,
	float *d_values)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i >= size){ return; }
	d_values[i] = curand_uniform(&d_states[i]);
}


__global__ void normalDist(
	int size,
	curandState_t *d_states,
	float *d_values)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i >= size){ return; }
	d_values[i] = curand_normal(&d_states[i]);
}


int main()
{
	unsigned int N = 100000;
	unsigned int numThreads = 256;

	unsigned int numBlocks = (N + numThreads - 1) / numThreads;

	curandState_t *d_states;
	cudaMalloc((void**)&d_states, N * sizeof(curandState_t));

	initializePRG <<< numBlocks , numThreads >>>(
		N, time(NULL), d_states);

	float *h_values = new float[N];
	for (int i = 0; i < N; i++)
	{
		h_values[i] = 0.0f;
	}

	float *d_values;

	cudaMalloc((void**)&d_values, N * sizeof(float));

	uniformDist <<< numBlocks, numThreads >>>(
		N, d_states, d_values);

	cudaMemcpy(h_values, d_values, N * sizeof(float), cudaMemcpyDeviceToHost);

	std::cout << std::setprecision(4);
	for (int i = 0; i < 100; i++)
	{
		std::cout << h_values[i] << " ";
		if ((i + 1) % 50 == 0)
		{
			std::cout << std::endl;
		}
	}

	normalDist <<< numBlocks, numThreads >>>(
		N, d_states, d_values);

	cudaMemcpy(h_values, d_values, N * sizeof(float), cudaMemcpyDeviceToHost);


	cudaFree(d_values);
	cudaFree(d_states);
	delete[] h_values;

    return 0;
}
