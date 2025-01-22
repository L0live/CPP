#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Zombie ex00 (ZombieHeap&Stack):" << std::endl;
	Zombie	*foo;

	std::cout << "\n# Birth and announce of \"Foo\" Zombie on the HEAP\n" << std::endl;
	foo = newZombie("Foo");
	foo->announce();

	std::cout << "\n# Birth, announce and death of \"Roo\" Zombie on the STACK\n" << std::endl;
	randomChump("Roo");
	std::cout << "\n# Death of \"Foo\" Zombie\n" << std::endl;
	delete foo;

	std::cout << "\nZombie ex01 (ZombieHorde):\n" << std::endl;
	int	hordeNbr = 10;
	Zombie	*horde = zombieHorde(hordeNbr, "Boo");

	for (int i = 0; i < hordeNbr; i++) {
		horde[i].announce();
	}
	delete[] horde;
	
	return 0;
}
