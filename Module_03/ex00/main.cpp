#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("Nathan");
    ClapTrap clapTrap2(clapTrap);
    ClapTrap clapTrap3 = clapTrap;
    
    std::cout << std::endl;

    clapTrap.attack("You");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(10);
    clapTrap.attack("You");
    clapTrap.beRepaired(5);
    for (size_t i = 0; i < 11; i++) {
        clapTrap3.attack("You");
    }
    clapTrap3.beRepaired(5);
    clapTrap3.takeDamage(10);
    
    std::cout << std::endl;

    return 0;
}