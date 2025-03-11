#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) {*this = src;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) {
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static int	detectType(std::string &input) {
	const int	error = 0;
	int	type = 1;
	bool	thereIsPoint = false;

	for (std::string::iterator i = input.begin(); i < input.end(); ++i) {
		if (*i < 32 || *i > 126)
			return error;
	}
	if (input.length() == 1 && (input[0] < 48 || input[0] > 57))
		return type;
	++type;
	for (std::string::iterator i = input.begin(); i < input.end(); ++i) {
		if (!isdigit(*i)) {
			if (*i == '.') {
				if (thereIsPoint)
					return error;
				thereIsPoint = true;
				++type;
			} else if (*i == 'f') {
				if (i + 1 != input.end())
					return error;
				if (!thereIsPoint)
					++type;
			} else if (i != input.begin() || *i != '-')
				return error;
		}
	}
	return type;
}

void    ScalarConverter::convert(std::string &input) {
	long long	i;
	double	d;

	switch (detectType(input)) {
	case 1:
		std::cout << "char: '" << input[0] << "'" << std::endl;
		i = input[0];
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << i << ".0f" << std::endl;
		std::cout << "double: " << i << ".0" << std::endl;
		break;
	case 2:
		i = atoll(input.c_str());
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << (char)i << "'" << std::endl;
		else if (i >= 0 && i <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << i << ".0f" << std::endl;
		std::cout << "double: " << i << ".0" << std::endl;
		break;
	case 3:
		d = atof(input.c_str());
		i = (int)d;
		if (d == i && i >= 32 && i <= 126)
			std::cout << "char: '" << (char)i << "'" << std::endl;
		else if (d == i && i >= 0 && i <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		if (d == i) {
			std::cout << "float: " << d << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		} else {
			std::cout << "float: " << d << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		break;
	default:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		break;
	}
}