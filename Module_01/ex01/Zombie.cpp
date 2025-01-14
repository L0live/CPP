#include "Zombie.hpp"

void	Zombie::announce(void) {std::cout << name << ": BraiiiiiiinnnzzzZ...\n";}

void Zombie::setName(std::string name) {this->name = name;}

Zombie::Zombie(std::string new_zname) :name(new_zname) {}

Zombie::Zombie() {}

Zombie::~Zombie() {std::cout << name << " got smashed\n";}
