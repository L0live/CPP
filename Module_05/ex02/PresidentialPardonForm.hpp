#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &src);
	PresidentialPardonForm & operator=(PresidentialPardonForm &src);
	~PresidentialPardonForm();

	std::string getTarget() const;

	void execute(Bureaucrat const & executor) const;
};

#endif
