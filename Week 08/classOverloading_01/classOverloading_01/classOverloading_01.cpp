// classOverloading_01.cpp : Defines the entry point for the console application.
//

#include <iostream>

class A
{
public:
	float x, y;
	A(float x_, float y_) :x(x_), y(y_){};
	bool operator==(A a_)
	{
		if (a_.x == x)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	A operator+(A a_)
	{
		return A(x + a_.x, y + a_.y);
	}
	void operator+=(A a_)
	{
		x += a_.x;
		y += a_.y;
	}
};


int main()
{
	A a1(1.2, 4.2);
	A a2(1.2, 5.3);

	std::cout << std::boolalpha;
	std::cout << (a1 == a2) << std::endl;

	A a3 = a1 + a2;

	std::cout << a3.x << "," << a3.y << std::endl;


	return 0;
}

