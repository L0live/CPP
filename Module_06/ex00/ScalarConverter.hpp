#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

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
