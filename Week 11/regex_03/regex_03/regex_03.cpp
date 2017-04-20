#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string subject("103.15");
	try {
		std::string REGEX = "";
		REGEX += "((\\+|-)?"; // Checks optional sign symbol
		REGEX += "[[:digit:]]+)"; // Checks for initial digits before decimal point
		REGEX += "(\\.(([[:digit:]]+)?))?"; // Checks for optional decimal point and then optional decimals
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