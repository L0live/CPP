#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &src);
	RobotomyRequestForm & operator=(RobotomyRequestForm &src);
	~RobotomyRequestForm();

	std::string getTarget() const;

	void execute(Bureaucrat const & executor) const;
};

#endif