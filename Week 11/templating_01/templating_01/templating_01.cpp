

#include "stdafx.h"
#include <exception>
#include <iostream>


template<typename T>
void exampleFunc(T t_)
{
	std::cout << t_ << std::endl;
}



int _tmain(int argc, _TCHAR* argv[])
{

	exampleFunc<double>(2.3);

	exampleFunc<int>(1);

	exampleFunc<char>('a');

	return 0;
}

