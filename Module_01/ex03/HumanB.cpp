#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->wpn->getType() << '\n';
}

void	HumanB::setWeapon(Weapon &w_type)
{
	this->wpn = &w_type;
}

HumanB::HumanB(std::string new_name)
{
	this->name = new_name;
}

HumanB::~HumanB()
{
}
