#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("DefaultTestSubject") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) {*this = src;}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src) {
    _target = src.getTarget();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() const {return _target;}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getSignedBool())
        throw UnsignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

    static int successProp = 1;

    std::cout << "**Some drilling noises**" << std::endl;
    if (successProp % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed." << std::endl;
    ++successProp;
}