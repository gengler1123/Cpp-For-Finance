// Week03_a.cpp : Defines the entry point for the console application.
//

#include <iostream>

class A
{
private:
	int x;
	int y = 0;
	float *arr;
	bool newArr = false;
public:
	A(){ x = 1; y = 2; };

	A(int x_, int y_, int size_);

	A(int x_, int y_ = 7){ x = x_; y = y_; };

	~A(); // Destructor.

	//A(int x_){ x = x_; }; // No good due to ambiguity of parameters.

	void change_x(int x_){ x = x_; };
	void change_y(int y_);
	int returnX(){ return x; };
	int returnY(){ return y; };
};

void A::change_y(int y_)
{
	y = y_;
}


A::A(int x_, int y_, int size_)
{
	x = x_;
	y = y_;

	arr = new float[size_];
	newArr = true;

}


A::~A()
{
	if (newArr)
	{
		std::cout << "Destroying This Class" << std::endl;
		delete[] arr;
	}
	else
	{
		std::cout << "Destroying, but no delete[]" << std::endl;
	}
}

int main()
{
	A a_0;

	std::cout << a_0.returnX() << "," << a_0.returnY() << std::endl;

	A a_1(5, 8);

	std::cout << a_1.returnX() << "," << a_1.returnY() << std::endl;

	A a_2(10);

	std::cout << a_2.returnX() << "," << a_2.returnY() << std::endl;

	A a_3(10, 10, 1000);


	A arrA[10];

	for (int i = 0; i < 10; i++)
	{
		std::cout << arrA[i].returnX() << std::endl;
	}

	arrA[1].change_x(100);

	A *ptrA;

	ptrA = &arrA[0];

	std::cout << "Accessing Via Pointer!" << std::endl;
	std::cout << ptrA->returnX() << std::endl;

	ptrA++;

	std::cout << ptrA->returnX() << std::endl;

	return 0;
}

