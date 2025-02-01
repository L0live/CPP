#include "ScavTrap.hpp"

int main() {
    ScavTrap scavTrap("Nathan");
    
    std::cout << std::endl;

    scavTrap.attack("You");
    scavTrap.guardGate();
    
    std::cout << std::endl;

    return 0;
}