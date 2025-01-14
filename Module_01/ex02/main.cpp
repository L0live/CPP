#include <iostream>

int main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "\n# The memory address:\n" << std::endl;
	std::cout << "The string variable: " << &string << std::endl;
	std::cout << "Held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Held by stringREF: " << &stringREF << std::endl;

	std::cout << "\n# The value:\n" << std::endl;
	std::cout << "The string variable: " << string << std::endl;
	std::cout << "Pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Pointed by stringREF: " << stringREF << std::endl;

	return 0;
}