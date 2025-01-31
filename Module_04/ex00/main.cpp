#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << animal->getType() << " " << std::endl;

    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    delete animal;
    delete cat;
    delete dog;

    return 0;
}