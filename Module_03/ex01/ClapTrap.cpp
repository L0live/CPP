#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const &target) {
	std::cout << "ClapTrap " << _name << " trying to attack..." << std::endl;
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else {
		if (_energyPoints == 0)
			std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!";
	if (_hitPoints <= 0)
		std::cout << " But is already dead...";
	std::cout << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " trying to be repaired..." << std::endl;
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else {
		if (_energyPoints == 0)
			std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	}
}