// threading_05.cpp : Defines the entry point for the console application.
//

#include <thread>
#include <iostream>



class threadGuard
{
private:
	std::thread &t;
public:
	explicit threadGuard(std::thread &t_) :t(t_){};

	~threadGuard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	threadGuard(threadGuard const&) = delete;
	threadGuard &operator=(threadGuard const&) = delete;
};


void count()
{
	for (int i = 0; i < 1000; i++)
	{
		std::cout << i << "\n";
	}
}


void func()
{
	std::thread t(count);
	threadGuard g(t);
}


int main()
{
	func();

	return 0;
}