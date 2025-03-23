#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string datafile) {
	std::ifstream	file(datafile.c_str());

	std::string	line;
	std::getline(file, line);
	if (line == "date,exchange_rate")
		std::getline(file, line);
	do {
		size_t	pos = line.find(',');
		float	currency = strtof(line.substr(pos + 1).c_str(), NULL);
		line.erase(pos);line.erase(7, 1);line.erase(4, 1);
		int	date = atoi(line.c_str());
		_data.insert(std::make_pair(date, currency));
	} while (std::getline(file, line));
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
	if (pos == std::string::npos || pos != 11 || input.size() < 14
		|| input[4] != '-' || input[7] != '-'
		|| input[10] != ' ' || input[12] != ' ')
		throw BadInputException(input);

	char	*endptr;
	float	value = strtof(input.substr(pos + 2).c_str(), &endptr);
	if (std::isnan(value) || *endptr)
		throw BadInputException(input);
	if (std::isinf(value) || value > 1000)
		throw TooLargeException();
	if (value < 0)
		throw NotPositiveException();

	input.erase(pos - 1);input.erase(7, 1);input.erase(4, 1);
	int	date = atoi(input.c_str());
	if (date % 100 > 31 || (date / 100) % 100 > 12)
		throw BadInputException(input);
	if (date < _data.begin()->first)
		throw OutOfBoundsException();

	float	exchangeRate;
	try {exchangeRate = _data.at(date) * value;
	} catch (std::exception	&e) {
		btcMap::iterator	it = _data.upper_bound(date);
		if (it != _data.begin())
			--it;
		exchangeRate = it->second * value;
	}
	return exchangeRate;
}

void	BitcoinExchange::exchangeRateFromFile(std::string inputFile) {
	std::ifstream	file(inputFile.c_str());
	if (!file.is_open())
		throw CouldNotOpenFileException();

	std::string	line;
	std::getline(file, line);
	if (line == "date | value")
		std::getline(file, line);
	do {try {
			float exchangeRate = getExchangeRate(line);
			size_t	pos = line.find('|');
			line.erase(pos, 1);line.insert(pos, "=>");
			std::cout << line << " = " << exchangeRate << std::endl;
		} catch(const std::exception& e) {std::cerr << e.what() << std::endl;}
		
	} while (std::getline(file, line));
	file.close();
}