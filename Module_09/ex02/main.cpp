#include "PmergeMe.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <ctime>
#include <cerrno>

std::ostream	&operator<<(std::ostream &o, const std::vector<int> &v) {
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		if (it == v.begin() + 5) {
			o << "[...]";
			break ;
		}
		o << *it << " ";
	}
	return o;
}

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Usage: " << av[0] << " n1 n2 n3 ... n" << std::endl;
		return 1;
	}

	try {
		std::vector<int>	v;
		std::deque<int>		d;
	
		for (int i = 1; i < ac; i++) {
			if (!std::string(av[i]).size())
			throw std::runtime_error("empty token is not allowed");
			
			char	*endptr;
			long	nbr = strtol(av[i], &endptr, 10);
			if (*endptr != '\0' || nbr < 0 || errno == ERANGE)
				throw std::runtime_error("invalid token => " + std::string(av[i]));

			v.push_back(static_cast<int>(nbr));
			d.push_back(static_cast<int>(nbr));
		}

		std::cout << "Before:	" << v << std::endl;

		clock_t start = clock();
		mergeInsertSort(v, v.size());
		clock_t end = clock();

		std::cout << "After:	" << v << std::endl;
	
		std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << end - start << " µs" << std::endl;
		
		start = clock();
		mergeInsertSort(d, d.size());
		end = clock();
		
		std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << end - start << " µs" << std::endl;
	} catch(std::exception	&e) {std::cerr << "Error: " << e.what() << std::endl;}
	
	return 0;
}