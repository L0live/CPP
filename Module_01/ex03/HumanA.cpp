#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->wpn.getType() << '\n';
}

HumanA::HumanA(std::string new_name, Weapon &w_type)
	: wpn(w_type), name(new_name) {}

HumanA::~HumanA()
{
}
