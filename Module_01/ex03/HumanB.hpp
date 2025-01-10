#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*wpn;
	std::string	name;
public:
	HumanB(std::string new_name);
	void	attack(void);
	void	setWeapon(Weapon &w_type);
	~HumanB();
};

#endif
