#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cmath>
#include <map>

class BitcoinExchange {
private:
	typedef std::map<int, float>	btcMap;

	btcMap	_data;

	BitcoinExchange();
public:
	BitcoinExchange(std::string dataFile);
	BitcoinExchange(BitcoinExchange &src);
	BitcoinExchange &operator=(BitcoinExchange &src);
	~BitcoinExchange();

	float	getExchangeRate(std::string input);
	void	exchangeRateFromFile(std::string inputFile);
};


#endif