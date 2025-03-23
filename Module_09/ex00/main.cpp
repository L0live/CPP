#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	try {BitcoinExchange	btc("data.csv");
		btc.exchangeRateFromFile(ac == 1?"":av[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}