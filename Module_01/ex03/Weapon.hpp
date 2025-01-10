#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string w_type);
	const std::string	getType(void);
	void	setType(std::string w_type);
	~Weapon();
};

#endif