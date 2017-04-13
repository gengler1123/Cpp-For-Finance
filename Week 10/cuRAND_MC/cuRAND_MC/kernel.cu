
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <ctime>
#include <iostream>

#include "curand.h"
#include "curand_kernel.h"


__global__ void initializePRG(
	int size, unsigned int seed, curandState_t *d_states)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i >= size){ return; }
	curand_init(
		seed,
		i,
		0,
		&d_states[i]);
}


__global__ void monteCarlo(
	int size, curandState_t *d_states, float *d_v,
	float mu, float sigma,
	int T, float dt)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i >= size){ return; }
	for (int t = 0; t < T; t++)
	{
		d_v[i] += d_v[i]*(dt*mu + sqrtf(dt)*curand_normal(&d_states[i])*sigma);
	}
}


int main()
{
	unsigned int N = 100000;
	unsigned int numThreads = 256;
	unsigned int numBlocks = (N + numThreads - 1) / numThreads;
	float mu = 0.1;
	float sigma = 0.2;

	int T = 252;
	float dt = 1 / 252.0f;

	float *h_traj = new float[N];
	for (int i = 0; i < N; i++)
	{
		h_traj[i] = 100.0f;
	}

	float *d_traj;
	cudaMalloc((void**)&d_traj, N*sizeof(float));

	cudaMemcpy(d_traj, h_traj, N * sizeof(float), cudaMemcpyHostToDevice);

	curandState_t *d_states;
	cudaMalloc((void**)&d_states, N * sizeof(curandState_t));

	initializePRG <<< numBlocks, numThreads >>>(
		N, time(NULL), d_states);

	monteCarlo <<< numBlocks, numThreads >>>(
		N, d_states, d_traj,
		mu, sigma,
		T, dt);

	cudaMemcpy(h_traj, d_traj, N * sizeof(float), cudaMemcpyDeviceToHost);

	float avgEnd = 0.0f;

	for (int i = 0; i < N; i++)
	{
		//std::cout << h_traj[i] << std::endl;
		avgEnd += h_traj[i];
	}
	avgEnd /= float(N);
	std::cout << "The Average Value Is " << avgEnd << std::endl;

	delete[] h_traj;
	cudaFree(d_states); cudaFree(d_traj);

    return 0;
}
