// tryCatch_02.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <exception>

class myException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "User Defined Exception";
	}
};


int main()
{
	try
	{
		throw myException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}