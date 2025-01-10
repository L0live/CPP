#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	human;

	if (ac == 2)
		human.complain(av[1]);
	else if (ac < 2)
		std::cout << "Error\nToo few arguments";
	else if (ac > 2)
		std::cout << "Error\nToo many arguments";
	return 0;
}
