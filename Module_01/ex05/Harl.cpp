#include "Harl.hpp"

Harl::Harl()
{
}

void	Harl::debug(void) {
	std::cout << "**the customer says something completely incomprehensible**\n";
}

void	Harl::info(void) {
	std::cout << "we all listen to what you have to say, with a smile of course\n";
}

void	Harl::warning(void) {
	std::cout << "I think we're going to need some help right now...🥹\n";
}

void	Harl::error(void) {
	std::cout << "HELP, PLEASE HELP !!!\n";
}

static int	level_to_case(std::string level)
{
	if (level == "DEBUG\0")
		return 1;
	else if (level == "INFO\0")
		return 2;
	else if (level == "WARNING\0")
		return 3;
	else if (level == "ERROR\0")
		return 4;
	return 0;
}

void	Harl::complain(std::string level)
{
	switch (level_to_case(level))
	{
	case 1:
		debug();
		break;
	case 2:
		info();
		break;
	case 3:
		warning();
		break;
	case 4:
		error();
		break;

	default:
		std::cout << "Error\nInvalid argument !\n";
		break;
	}
}

Harl::~Harl()
{
}
