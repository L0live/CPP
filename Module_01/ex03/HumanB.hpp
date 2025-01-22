#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

public:

	HumanB(std::string new_name);
	~HumanB();

	void	attack(void);
	void	setWeapon(Weapon &w_type);

private:

	std::string	name;
	Weapon		*wpn;

};

#endif
