// regex_04.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <regex>
#include <string>



int main()
{
	std::string subject("carra");
	try {
		std::string REGEX = "";
		REGEX += "[rf]+at";
		std::regex re(REGEX);
		std::sregex_iterator next(subject.begin(), subject.end(), re);
		std::sregex_iterator end;
		while (next != end) {
			std::smatch match = *next;
			std::cout << match.str() << "\n";
			next++;
		}
	}
	catch (std::regex_error& e) {
		std::cout << "Error: " << std::endl;
		std::cout << e.what() << std::endl;
		// Syntax error in the regular expression
	}

	return 0;

}