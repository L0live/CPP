#include "Form.hpp"

Form::Form()
: _name("DefaultForm"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src)
: _name(src.getName()), _signed(src.getSignedBool()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {}

Form &Form::operator=(Form const &src) {
    this->_signed = src.getSignedBool();
    // We can't for others
    return *this;
}

Form::~Form() {}

const std::string   Form::getName() const {return _name;}

bool    Form::getSignedBool() const {return _signed;}

int   Form::getGradeToSign() const {return _gradeToSign;}

int   Form::getGradeToExec() const {return _gradeToExec;}

void	Form::beSigned(Bureaucrat &whoSign) {
    if (whoSign.getGrade() > _gradeToSign) {
        std::cout << whoSign.getName() << " couldn’t sign " << _name << " because ";
		throw GradeTooLowException();
    }
    _signed = true;
    std::cout << whoSign.getName() << " signed " << _name << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Form &src) {
    out << src.getName() << ", " << (src.getSignedBool() ? "signed" : "unsigned") << " form";
    out << ", gradeToSign: " << src.getGradeToSign() << ", gradeToExec: " << src.getGradeToExec();
    return out;
}