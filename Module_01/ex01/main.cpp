#include "Zombie.hpp"

int	main(void) {
	int	hordeNbr = 10;
	Zombie	*horde = zombieHorde(hordeNbr, "Boo");

	for (int i = 0; i < hordeNbr; i++) {
		horde[i].announce();
	}
	delete[] horde;
	
	return 0;
}
