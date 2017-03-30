// threading_02.cpp : Defines the entry point for the console application.
//

#include <thread>
#include <iostream>

class some_task
{
public:
	void operator()()
	{
		std::cout << "Hello World!\n";
	}
};

int main()
{
	some_task f;
	std::thread t(f);

	t.join();

	std::cout << "Temporary Variable" << std::endl;

	/*
	std::thread t2(some_task);
	t2.join();
	*/

	/*
	std::thread t2(some_task());
	t2.join();
	*/

	std::thread t2((some_task()));
	t2.join();

	std::thread t3{ some_task() };
	t3.join();

	return 0;
}
