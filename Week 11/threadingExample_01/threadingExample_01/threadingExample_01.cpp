// threadingExample_01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>
#include <random>
#include <ctime>


const unsigned int N = 10;


class Example
{
private:
	std::mt19937 gen;
	std::thread t_;
	std::uniform_real_distribution<float> dist;

	float value = 0;

	void interiorFunction()
	{
		otherFunction();
	}


	void otherFunction()
	{
		value += dist(gen);
	}


public:
	~Example()
	{
		if (t_.joinable())
		{
			t_.join();
		}
	}


	void setupFunction(unsigned int offset_)
	{
		gen = std::mt19937(time(NULL) + offset_);
		dist = std::uniform_real_distribution<float>(0.0, 1.0);
	};

	void createThread()
	{
		t_ = std::thread(&Example::interiorFunction, this);
	}

	void joinThread()
	{
		t_.join();
	}

	void printValue()
	{
		std::cout << value << std::endl;
	}

};



int main()
{

	Example *E = new Example[N];

	for (unsigned int i = 0; i < N; i++)
	{
		E[i].setupFunction(i);
		E[i].createThread();
	}

	std::cout << "Printing Out Results:" << std::endl;

	for (unsigned int i = 0; i < N; i++)
	{
		E[i].joinThread();
		E[i].printValue();
	}



	return 0;
}