#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("DefaultPardoned") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src) {*this = src;}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src) {
    _target = src.getTarget();
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string	PresidentialPardonForm::getTarget() const {return _target;}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getSignedBool())
        throw UnsignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}