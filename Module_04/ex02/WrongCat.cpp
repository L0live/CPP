#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    (void)other;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "**Woem Woem**" << std::endl;
}