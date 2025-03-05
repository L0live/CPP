#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string   _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat & operator=(Bureaucrat const & src);
	~Bureaucrat();

	class GradeTooHighException  : public std::exception {
	public:
		GradeTooHighException() {}
		const char* what() const throw() { return "Exception GradeTooHigh refused to continue"; }
	};

	class GradeTooLowException  : public std::exception {
	public:
		GradeTooLowException() {}
		const char* what() const throw() { return "Exception GradeTooLow refused to continue"; }
	};

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(Form & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);


#endif