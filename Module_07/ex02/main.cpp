#include "Array.hpp"

int main(void) {
	try {
		Array<int>  nbrs(10);
	
		for (size_t i = 0; i < nbrs.size(); i++) {
			nbrs[i] = i + 1;
		}

		Array<int>	tmp_nbrs(nbrs);

		tmp_nbrs = nbrs;
		for (size_t i = 0; i < tmp_nbrs.size(); i++) {
			tmp_nbrs[i] = tmp_nbrs.size() - i;
		}

		for (size_t i = 0; i < nbrs.size(); i++) {
			std::cout << "nbrs[" << i << "]: " << nbrs[i] << std::endl;
			std::cout << "tmp_nbrs[" << i << "]: " << tmp_nbrs[i] << std::endl;
		}

	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Array<int>  nbrs(24);

		nbrs[42] = 42;
		std::cout << "OutOfBounds failed?: " << nbrs[42] << std::endl;

	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}