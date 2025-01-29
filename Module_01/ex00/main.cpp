#include "Zombie.hpp"

int	main(void) {
	Zombie	*foo;

	std::cout << "\n# Birth and announce of \"Foo\" Zombie on the HEAP\n\n";
	foo = newZombie("Foo");
	foo->announce();

	std::cout << "\n# Birth, announce and death of \"Roo\" Zombie on the STACK\n\n";
	randomChump("Roo");
	std::cout << "\n# Death of \"Foo\" Zombie\n\n";
	delete foo;
	return 0;
}
