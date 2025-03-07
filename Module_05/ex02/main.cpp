#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    
    try {
        Bureaucrat  nathan("Nathan", 1);
        std::cout << nathan << std::endl;
        ShrubberyCreationForm form;
        std::cout << form << std::endl;
        nathan.signForm(form);
        std::cout << form << std::endl;
        nathan.executeForm(form);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat  nathan("Nathan", 1);
        std::cout << nathan << std::endl;
        RobotomyRequestForm form(nathan.getName());
        std::cout << form << std::endl;
        nathan.signForm(form);
        std::cout << form << std::endl;
        nathan.executeForm(form);
        nathan.executeForm(form);
        nathan.executeForm(form);
        nathan.executeForm(form);
        nathan.executeForm(form);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat  nathan("Nathan", 20);
        std::cout << nathan << std::endl;
        PresidentialPardonForm form("Nathan");
        std::cout << form << std::endl;
        nathan.executeForm(form);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}