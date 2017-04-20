// templating_02.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>

template <class T>
class Node
{
private:
	T info_;
	std::string key_;
public:
	Node(T t_) :info_(t_)
	{};

	void giveInfo()
	{
		std::cout << info_ << std::endl;
	}

};


template <class T>
class NodeList
{
private:
	std::vector<Node<T>> v;
	
public:
	Node<T> *ptr;
	void addNode(Node<T> t_)
	{
		v.push_back(t_);
	}

	void LookAt(Node<T> *t_)
	{
		ptr = t_;
	}
};


int main()
{
	Node<int> N(10);

	N.giveInfo();

	NodeList<int> NL;

	NL.addNode(N);

	NL.LookAt(&N);

	NL.ptr->giveInfo();

	return 0;
}
