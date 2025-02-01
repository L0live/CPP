#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this == &other)
        return *this;
    delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "**Woof Woof**" << std::endl;
}

void Dog::setIdea(const std::string& idea, int index) {
    _brain->setIdea(idea, index);
}

std::string Dog::getIdea(int index) const {
    return _brain->getIdea(index);
}