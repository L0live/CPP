#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

public:

	Weapon(std::string w_type);
	~Weapon();

	const std::string&	getType(void) const;
	void	setType(std::string w_type);

private:

	std::string type;

};

#endif