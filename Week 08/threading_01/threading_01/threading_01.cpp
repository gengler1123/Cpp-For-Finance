// threading_01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>


void hello()
{
	std::cout << "Hello World\n";
}

int main()
{
	std::thread t1(hello);
	std::thread t2(hello);
	std::thread t3(hello);
	/* 
	We need to 'join' the threads otherwise the program may finish before the threads 
	accomplish their tasks.
	*/
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
