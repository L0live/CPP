#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {(void)src;}

Intern & Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

Intern::~Intern() {}

static int identifyForm(std::string formName) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i])
			return i;
	}
	return -1;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	switch (identifyForm(formName)) {
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			std::cout << "I-I'm sorry, sir... I—I couldn't... I couldn't find the form you requested..." << std::endl;
			return NULL;
	}
}