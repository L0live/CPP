#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <sstream>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &src);
	ScalarConverter &operator=(ScalarConverter &src);
	~ScalarConverter();
public:
	static void	convert(std::string &input);
};

#endif
