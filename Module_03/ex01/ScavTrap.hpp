#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &src);
        void attack(std::string const &target);
        void guardGate();
};