#include "Bureaucrat.hpp"

int main(void) {

    try {
        Bureaucrat  nathan("Nathan", 150);
        std::cout << "Step passed successfully" << std::endl;
        nathan.increment();
        std::cout << "Step passed successfully" << std::endl;
        nathan.decrement();
        std::cout << "Step passed successfully" << std::endl;
        nathan.decrement();
        std::cout << "Step passed successfully" << std::endl;
        std::cout << nathan << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}