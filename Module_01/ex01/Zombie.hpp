#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:

	Zombie(std::string name);
	Zombie();
	~Zombie();

	void setName(std::string name);
	void	announce(void);

private:

	std::string name;
	
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif