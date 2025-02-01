#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    void makeSound() const;
    void setIdea(const std::string& idea, int index);
    std::string getIdea(int index) const;

private:
    Brain* _brain;

};

#endif