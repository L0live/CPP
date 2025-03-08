#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    
    try {
        Bureaucrat  nathan("Nathan", 1);
        Intern      intern;
        AForm       *form;

        form = intern.makeForm("shrubbery creation", "Field");
        if (!form)
            return 1;
        std::cout << *form << std::endl;
        nathan.signForm(*form);
        nathan.executeForm(*form);
        delete form;

        std::cout << std::endl;

        form = intern.makeForm("robotomy request", "Nathan");
        if (!form)
            return 1;
        std::cout << *form << std::endl;
        nathan.signForm(*form);
        nathan.executeForm(*form);
        delete form;

        std::cout << std::endl;

        form = intern.makeForm("presidential pardon", "Nathan");
        if (!form)
            return 1;
        std::cout << *form << std::endl;
        nathan.signForm(*form);
        nathan.executeForm(*form);
        delete form;

        std::cout << std::endl;

        form = intern.makeForm("dragon taming", "Fafnir");
        if (!form)
            return 1;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}