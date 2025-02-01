#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete meta;
    delete dog;
    delete cat;

    std::cout << std::endl;

    Dog dog1;
    Dog dog2;
    Cat cat1;

    std::cout << std::endl;

    dog1.setIdea("Dog1 idea", 0);
    dog2 = dog1;
    dog2.setIdea("Dog2 idea", 1);
    dog2.setIdea("Dog2 idea", -2);

    cat1.setIdea("Cat1 idea", 0);
    Cat cat2(cat1);
    cat2.setIdea("Cat2 idea", 1);
    cat2.setIdea("Cat2 idea", 101);

    std::cout << std::endl;

    std::cout << dog1.getIdea(0) << std::endl;
    std::cout << dog1.getIdea(1) << std::endl;
    std::cout << dog2.getIdea(0) << std::endl;
    std::cout << dog2.getIdea(1) << std::endl;
    std::cout << dog2.getIdea(-2) << std::endl;

    std::cout << cat1.getIdea(0) << std::endl;
    std::cout << cat1.getIdea(1) << std::endl;
    std::cout << cat2.getIdea(0) << std::endl;
    std::cout << cat2.getIdea(1) << std::endl;
    std::cout << cat2.getIdea(101) << std::endl;

    std::cout << std::endl;

    return 0;
}
