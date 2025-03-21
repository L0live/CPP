#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <map>

class BitcoinExchange {
private:
	typedef std::map<std::string, float>	btcMap;

	btcMap	_data;

	BitcoinExchange();
public:
	BitcoinExchange(std::string &dataFile);
	BitcoinExchange(BitcoinExchange &src);
	BitcoinExchange &operator=(BitcoinExchange &src);
	~BitcoinExchange();

	class CouldNotOpenFileException : public std::exception {
	public:
		CouldNotOpenFileException() {}
		const char* what() const throw() {return "Error: could not open file.";}
	};

	class NotPositiveException : public std::exception {
	public:
		NotPositiveException() {}
		const char* what() const throw() {return "Error: not a positive number.";}
	};
	
	class TooLargeException : public std::exception {
	public:
		TooLargeException() {}
		const char* what() const throw() {return "Error: too large a number.";}
	};
	
	class BadInputException : public std::exception {
	private:
		std::string	_context;
	public:
		BadInputException(std::string context) : _context(context) {}
		const char* what() const throw() {return ("Error: bad input => " + _context).c_str();}
	};

	float   getExchangeRate(std::string input);
};


#endif