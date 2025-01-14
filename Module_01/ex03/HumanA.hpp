#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

public:

	HumanA(std::string new_name, Weapon &w_type);
	~HumanA();

	void	attack(void);

private:

	std::string	name;
	Weapon		&wpn;

};

#endif
