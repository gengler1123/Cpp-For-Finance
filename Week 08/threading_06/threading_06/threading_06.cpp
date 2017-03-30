// threading_06.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>


void f(int i, int j)
{
	std::cout << "First Int: " << i << ", Second Int: " << j << "\n";
}

void threadID(int idx)
{
	std::cout << "Hello from Thread " << idx << "\n";
}

int main()
{
	std::thread t(f, 1, 2);
	t.join();

	for (int i = 0; i < 10; i++)
	{
		std::thread t(threadID, i);
		t.detach();
	}

	for (int j = 0; j < 100000; j++)
	{
		if (j == 9999)
		{
			std::cout << "End of For Loop" << std::endl;
		}
	}

	return 0;
}

