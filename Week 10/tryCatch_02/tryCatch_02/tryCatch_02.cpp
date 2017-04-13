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
} myex;


int main()
{
	try
	{
		throw myex;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}