#include "Weapon.hpp"

const std::string&	Weapon::getType(void) const {return type;}

void	Weapon::setType(std::string w_type) {type = w_type;}

Weapon::Weapon(std::string w_type) :type(w_type) {}

Weapon::~Weapon() {}