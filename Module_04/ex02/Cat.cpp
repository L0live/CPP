#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
    _type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this == &other)
        return *this;
    _brain = new Brain(*other._brain);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "**Meow Meow**" << std::endl;
}

void Cat::setIdea(const std::string& idea, int index) {
    _brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}