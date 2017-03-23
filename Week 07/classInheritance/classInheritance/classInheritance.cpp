// classInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class A
{
private:
	int a_Pri = 1;
protected:
	int a_Pro = 2;
public:
	A(int x_)
	{
		std::cout << "A" << std::endl;
		a_Pro = x_;
	};
	virtual void changePublic(int x)
	{
		a_Pub = x;
	};

	int a_Pub = 3;
};

class B : public A
{
private:

protected:
	float b_pro;
	float y;
	const int x;
public:
	B(int x_, float y_) : A(x_), y(y_), x(x_)
	{
		std::cout << "IN B" << std::endl;
		b_pro = y_;
	}

	void changePublic(int x)
	{
		a_Pub = 3 * x * x;
	};
	
	void printValues()
	{
		std::cout << a_Pub << std::endl;
		std::cout << a_Pro << std::endl;
		//std::cout << a_Pri << std::endl;
	}
};

class C : private A
{
private:

protected:

public:
	void printValues()
	{
		std::cout << a_Pub << std::endl;
		std::cout << a_Pro << std::endl;
	}
};

class D :protected A
{
private:

protected:

public:
	void printValues()
	{
		std::cout << a_Pub << std::endl;
		std::cout << a_Pro << std::endl;
	}
};


class X
{
public:
	int y;
	X(int y_)
	{
		std::cout << "IN CLASS X" << std::endl;
		y = y_;
	}
};

class E : public X, B
{
public:
	E() : X(10), B(3, 4.5f)
	{
		std::cout << X::y << std::endl;
		std::cout << B::y << std::endl;
		std::cout << a_Pub << std::endl;
	};
};


int _tmain(int argc, _TCHAR* argv[])
{
	//A a(10);
	//B b(10,5.0f);

	//int x(10);

	E e;
	/*
	a.changePublic(10);
	b.changePublic(10);

	std::cout << a.a_Pub << std::endl;

	std::cout << b.a_Pub << std::endl;

	A *aa = new A;
	B *bb = new B;

	std::cout << std::endl;

	aa->changePublic(10);
	bb->changePublic(10);

	std::cout << aa->a_Pub << std::endl;
	std::cout << bb->a_Pub << std::endl;

	std::cout << std::endl;

	A *x = bb;
	x->changePublic(10);

	std::cout << aa->a_Pub << std::endl;
	std::cout << bb->a_Pub << std::endl;
	*/
	return 0;
}

