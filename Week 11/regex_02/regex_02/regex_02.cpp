#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string subject("This is a test. +10 abcd -10");
	try {
		std::string REGEX = "";
		REGEX += "(-)?";
		REGEX += "[[:digit:]]";
		std::regex re(REGEX);//"(\\+|-)?[[:digit:]]+");
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