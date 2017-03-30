// classThreading_02.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>



class AB
{
private:
	float x, y;
	float z;
	std::thread t_;

	void constructor()
	{
		z = x + y;
	}

	void doubleVals()
	{
		x *= 2.0f;
		y *= 2.0f;
		z *= 2.0f;
	}
public:
	AB(float x_, float y_) :x(x_), y(y_)
	{
		t_ = std::thread(&AB::constructor, this);
	}

	~AB()
	{
		if (t_.joinable())
		{
			t_.join();
		}
	}

	void waitForThread()
	{
		if (t_.joinable())
		{
			t_.join();
		}
	}

	void runDouble()
	{
		waitForThread();
		t_ = std::thread(&AB::doubleVals, this);
	}

	void printVals()
	{
		waitForThread();
		std::cout << "(x,y,z) = (" << x << "," << y << "," << z << ")\n";
	}

};

void f()
{
	std::cout << "A" << std::endl;
}

void g()
{
	std::cout << "B" << std::endl;
}


int main()
{

	AB a(2.3, 1.0);
	a.printVals();
	a.runDouble();
	a.printVals();


	return 0;
}