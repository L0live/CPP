#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &src);
		Intern & operator=(const Intern &src);
		~Intern();

		AForm *makeForm(std::string formName, std::string target);
};

#endif