#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string   _name;
	bool    _signed;
	const int   _gradeToSign;
	const int   _gradeToExec;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(Form const &src);
	Form & operator=(Form const & src);
	~Form();

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

	const std::string   getName() const;
	bool    getSignedBool() const;
	int   getGradeToSign() const;
	int   getGradeToExec() const;

	void	beSigned(Bureaucrat &whoSign);
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif