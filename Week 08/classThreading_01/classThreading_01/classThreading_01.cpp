// classThreading_01.cpp : Defines the entry point for the console application.
//

#include <thread>
#include <iostream>
#include <vector>

class A
{
private:
	int x, y;
	int z;
	std::thread t_;
	/* Private Thread Functions */
	void constructor()
	{
		z = x + y;
	}
	
public:

	void wait()
	{
		t_.join();
	}

	A(int x_, int y_) :x(x_), y(y_)
	{
		t_ = std::thread(&A::constructor,this);
	}

	~A()
	{
		if (t_.joinable())
		{
			t_.join();
		}
	}

	void giveZ()
	{
		std::cout << "Z = " << z << std::endl;
	}
};


int main()
{
	std::vector<A> V;
	for (int i = 0; i < 10000; i++)
	{
		A a(i, i + 1);
		V.push_back(a);
	}
	
	

	return 0;
}
