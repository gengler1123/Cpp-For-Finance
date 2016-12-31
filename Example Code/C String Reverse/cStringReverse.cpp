#include "stdafx.h"
#include <iostream>

void str_reverse(char *str);

int main()
{

	char Word[100];

	std::cin.getline(Word, 99);

	std::cout << Word << std::endl;

	std::cout << sizeof(Word)/sizeof(char) << std::endl;

	std::cout << std::strlen(Word) << std::endl;

	str_reverse(Word);

	std::cout << Word << std::endl;

    return 0;
}


void str_reverse(char *str)
{
	std::size_t len = std::strlen(str);
	char buffer;
	std::size_t j;
	for (std::size_t ind = 0; ind < len / 2; ind++)
	{
		j = len - ind - 1;
		buffer = str[j];
		str[j] = str[ind];
		str[ind] = buffer;
	}
}
