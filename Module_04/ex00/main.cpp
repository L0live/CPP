#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << animal->getType() << " say: ";
    animal->makeSound();
    std::cout << cat->getType() << " say: ";
    cat->makeSound();
    std::cout << dog->getType() << " say: ";
    dog->makeSound();
    std::cout << wrongAnimal->getType() << " say: ";
    wrongAnimal->makeSound();
    std::cout << wrongCat->getType() << " say: ";
    wrongCat->makeSound();
    
    std::cout << std::endl;

    delete animal;
    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}