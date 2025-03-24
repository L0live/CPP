#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	try {
		std::cout << RPN::calculateRPN(av[1]) << std::endl;
	} catch (std::runtime_error &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}