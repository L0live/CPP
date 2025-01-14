#include "HumanA.hpp"

void	HumanA::attack(void) {
	std::cout << name << " attacks with their " << wpn.getType() << std::endl;
}

HumanA::HumanA(std::string new_name, Weapon &w_type)
	:name(new_name), wpn(w_type) {}

HumanA::~HumanA() {}
