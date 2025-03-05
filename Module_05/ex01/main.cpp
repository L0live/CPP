#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    
    try {
        Bureaucrat  nathan("Nathan", 150);
        std::cout << nathan << std::endl;
        nathan.increment();
        std::cout << nathan << std::endl;
        nathan.decrement();
        std::cout << nathan << std::endl;
        Form form("Test", 56, 42);
        std::cout << form << std::endl;
        nathan.signForm(form);
        std::cout << form << std::endl;
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