// regex_01.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string subject("Name: John Doe");
	std::string result;
	try {
		std::regex re("Name: (.*)");
		std::smatch match;
		if (std::regex_search(subject, match, re) && match.size() > 1) {
			result = match.str(1);
		}
		else {
			result = std::string("");
		}
		std::cout << result << std::endl;
	}
	catch (std::regex_error& e) {
		// Syntax error in the regular expression
	}



	return 0;

}