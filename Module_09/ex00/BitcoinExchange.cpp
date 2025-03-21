#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string &datafile) {
	std::ifstream	file(datafile);
	if (!file.is_open())
		throw CouldNotOpenFileException();

	std::string	line;
	while (std::getline(file, line)) {
		size_t	pos = line.find(',');
		float	currency = strtof(line.substr(pos + 1).c_str(), NULL);
		std::string	date = line.erase(pos);
		_data.insert(std::make_pair(date, currency));
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src) {*this = src;}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src) {
	if (this != &src)
		_data = src._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

float	BitcoinExchange::getExchangeRate(std::string input) {
	size_t	pos = input.find('|');
	if (pos == std::string::npos)
		throw BadInputException(input);
	float	value = strtof(input.substr(pos + 2).c_str(), NULL);
	if (std::isnan(value))
		throw BadInputException(input);
	if (std::isinf(value) || value > 2147483647)
		throw TooLargeException();
	if (value < 0)
		throw NotPositiveException();
	std::string	date = input.erase(pos - 1);
}