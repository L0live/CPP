#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

    std::cout << "# Birth of " << N << " zombies in a horde\n" << std::endl;
    
    Zombie  *horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    return horde;
}