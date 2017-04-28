// templating_04.cpp : Defines the entry point for the console application.
//

#include <iostream>


class A
{
protected:
	int id;


public:
	A(int id_) :id(id_)
	{};
	virtual void giveID()
	{
		std::cout << id << std::endl;
	}
};


template<class T>
class B :public A
{
protected:
	T t;

public:
	B(T t_, int id_) :A(id_), t(t_)
	{};

	virtual void giveID()
	{
		std::cout << id << "," << t << std::endl;
	}
};


int main()
{
	A a(10);

	B<int> b(10, 2);

	B<double> c(10.2, 5);

	A *ptr = &a;

	ptr->giveID();

	ptr = &b;

	ptr->giveID();

	ptr = &c;

	ptr->giveID();

	return 0;
}