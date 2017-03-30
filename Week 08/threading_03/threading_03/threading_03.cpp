// threading_03.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>


void WaitHello()
{
	int x = 0;
	while (x++ < 1000000)
	{
	}
	std::cout << "Hello Finally\n";
}


int main()
{
	std::thread t(WaitHello);

	std::cout << "Happens First" << std::endl;

	t.join();


	return 0;
}