#include "Bureaucrat.hpp"

int main(void) {

    try {
        Bureaucrat  nathan("Nathan", 150);
        std::cout << nathan << std::endl;
        nathan.increment();
        std::cout << nathan << std::endl;
        nathan.decrement();
        std::cout << nathan << std::endl;
        nathan.decrement();
        std::cout << nathan << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat  nathan("Nathan", 1);
        std::cout << nathan << std::endl;
        nathan.decrement();
        std::cout << nathan << std::endl;
        nathan.increment();
        std::cout << nathan << std::endl;
        nathan.increment();
        std::cout << nathan << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat  nathan("Nathan", 151);
        std::cout << nathan << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}