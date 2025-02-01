#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    (void)other;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "**Woof Woof**" << std::endl;
}