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
	int a_Pub = 3;
};

class B : public A
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

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	B b;
	C c;
	D d;


	b.printValues();
	c.printValues();
	d.printValues();



	return 0;
}

