// threading_04.cpp : Defines the entry point for the console application.
//

#include <thread>
#include <iostream>

class Example
{
public:
	int i;
	Example(int i_) :i(i_){};

	void operator()()
	{
		for (unsigned int j = 0; j < 1000000; j++)
		{
			i = j;
		}
		std::cout << i << std::endl;
	}
};


int main()
{
	int local_Variable = 0;
	Example E(local_Variable);

	std::thread t(E);
	t.join();
	
	std::cout << E.i << std::endl;
	std::cout << local_Variable << std::endl;



	
	return 0;
}