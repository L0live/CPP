#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

class PmergeMe {
private:
	PmergeMe();
public:
	~PmergeMe();

	std::vector<int>    &sort(std::vector<int> &container);
};


#endif