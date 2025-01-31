#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
    _type = "Undefined animal";
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    (void)other;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "**Strange noise**" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}