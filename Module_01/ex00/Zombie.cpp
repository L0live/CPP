#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string new_zname)
{
	this->name = new_zname;
}

Zombie::~Zombie()
{
	std::cout << name << " got smashed\n";
}
