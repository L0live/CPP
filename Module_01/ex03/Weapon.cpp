#include "Weapon.hpp"

const std::string	Weapon::getType(void)
{
	return this->type;
}

void	Weapon::setType(std::string w_type)
{
	this->type = w_type;
}

Weapon::Weapon(std::string w_type)
{
	this->type = w_type;
}

Weapon::~Weapon()
{
}