#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    _type = "Undefined WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    (void)other;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "**Strange Wrong noise**" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}