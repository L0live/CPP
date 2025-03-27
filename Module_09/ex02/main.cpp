#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Usage: " << av[0] << " n1 n2 n3 ... n" << std::endl;
		return 1;
	}

	try {
		std::vector<int>	container;
	
		char	*endptr;
		for (size_t i = 1; i < ac; i++) {
			if (!std::string(av[i]).size())
				continue ;
			long	nbr = std::strtol(av[i], &endptr, 10);
			if (*endptr != '\0' || nbr < 0 || errno == ERANGE)
				throw std::runtime_error("Error: invalid input => '" + std::string(av[i]) + "'");
			container.push_back(static_cast<int>(nbr));
		}
		if (!container.size())
			throw std::runtime_error("Error: sequence of integers is empty");
		
		std::cout << "Before:	";
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		} std::cout << std::endl;
		
	} catch(std::exception	&e) {std::cerr << e.what() << std::endl;}
	
	return 0;
}