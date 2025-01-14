#include "HumanB.hpp"

void	HumanB::attack(void) {
	std::cout << name << " attacks with their ";
	
	if (wpn)
		std::cout << wpn->getType() << std::endl;
	else
		std::cout << "...hand?" << std::endl;
}

void	HumanB::setWeapon(Weapon &w_type) {wpn = &w_type;}

HumanB::HumanB(std::string new_name)
	:name(new_name), wpn(NULL) {}

HumanB::~HumanB() {}
