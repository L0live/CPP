#include <iostream>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int k = 1; av[k]; k++)
		{
			for (int i = 0; av[k][i]; i++)
			{
				if (av[k][i] >= 'a' && av[k][i] <= 'z')
					av[k][i] -= 32;
			}
			
		}
		for (int k = 1; av[k]; k++)
			std::cout << av[k];
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (0);
}