#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string subject("7893154972");
	try {
		std::string REGEX = "";
		REGEX += "[7-9][\d]{9}";
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