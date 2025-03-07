#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string   _name;
	bool    _signed;
	const int   _gradeToSign;
	const int   _gradeToExec;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(AForm const &src);
	AForm & operator=(AForm const & src);
	virtual ~AForm();

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

	class UnsignedException  : public std::exception {
	public:
		UnsignedException() {}
		const char* what() const throw() { return "Exception Unsigned refused to continue"; }
	};

	const std::string   getName() const;
	bool    getSignedBool() const;
	int   getGradeToSign() const;
	int   getGradeToExec() const;

	void	beSigned(Bureaucrat &whoSign);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif