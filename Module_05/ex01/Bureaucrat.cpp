#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {*this = src;}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	_grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {return _name;}

int	Bureaucrat::getGrade() const {return _grade;}

void	Bureaucrat::increment() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrement() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(Form &form) {form.beSigned(*this);}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return out;
}