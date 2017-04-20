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


int main()
{
	Node<int> N(10);

	N.giveInfo();

	std::vector<int> v;
	Node<std::vector<int>> M(v);

	M.giveInfo();

	return 0;
}
