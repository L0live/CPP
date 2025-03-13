#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) {*this = src;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) {
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string &literal) {
    char *endptr;
    double d = strtod(literal.c_str(), &endptr);

    if (*endptr == '\0' || (literal.length() > 1 && *endptr == 'f' && endptr[1] == '\0')) {
        std::cout << "char: ";
        if (d < 32 || d > 126 || std::isnan(d) || std::isinf(d))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(d) << std::endl;
		if (d == static_cast<int>(d))
			std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		std::cout.unsetf(std::ios::fixed);
    } else if (literal.length() == 1) {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		std::cout.unsetf(std::ios::fixed);
    } else {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
    }
}