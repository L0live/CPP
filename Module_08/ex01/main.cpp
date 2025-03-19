#include "Span.hpp"
#include <ctime>
#include <list>

int main() {
	try {std::cout << "Subject test:" << std::endl;
		Span	sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	try {std::cout << "addSomeNumbers() test:" << std::endl;
		std::vector<int>	tmp;
		Span	sp(10000);

		srand(time(0));
		for (size_t i = 0; i < 10000; i++) {
			tmp.push_back(rand() % 10000 - 5000); // between -5000 and 5000
		}
		sp.addSomeNumbers(tmp);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << "Errors test:" << std::endl;
	try {
		Span	sp(0);

		sp.addNumber(6);
	} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	try {
		Span	sp(0);

		std::cout << sp.shortestSpan() << std::endl;
	} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	return 0;
}  