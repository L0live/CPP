#include "Harl.hpp"

Harl::Harl() {std::cout << "Constructor call" << std::endl;}

Harl::~Harl() {std::cout << "Destructor call" << std::endl;}

void Harl::complain(std::string level) {
	typedef void	(Harl::*complainMethod)(void);
	complainMethod methods[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*methods[i])();
			return ;
		}
	}
	std::cout << "Unknown level: " << level << std::endl;
}

void	Harl::debug() {std::cout << "DEBUG explain" << std::endl;}

void	Harl::info() {std::cout << "INFO explain" << std::endl;}

void	Harl::warning() {std::cout << "WARNING explain" << std::endl;}

void	Harl::error() {std::cout << "ERROR explain" << std::endl;}