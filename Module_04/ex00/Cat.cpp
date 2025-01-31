#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    (void)other;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "**Meow Meow**" << std::endl;
}