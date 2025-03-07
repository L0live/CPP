#include "AForm.hpp"

AForm::AForm()
: _name("DefaultForm"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &src)
: _name(src.getName()), _signed(src.getSignedBool()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {}

AForm &AForm::operator=(AForm const &src) {
    this->_signed = src.getSignedBool();
    // We can't for others
    return *this;
}

AForm::~AForm() {}

const std::string   AForm::getName() const {return _name;}

bool    AForm::getSignedBool() const {return _signed;}

int   AForm::getGradeToSign() const {return _gradeToSign;}

int   AForm::getGradeToExec() const {return _gradeToExec;}

void	AForm::beSigned(Bureaucrat &whoSign) {
    if (whoSign.getGrade() > _gradeToSign) {
        std::cout << whoSign.getName() << " couldn’t sign " << _name << " because ";
		throw GradeTooLowException();
    }
    _signed = true;
    std::cout << whoSign.getName() << " signed " << _name << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &src) {
    out << src.getName() << ", " << (src.getSignedBool() ? "signed" : "unsigned") << " form";
    out << ", gradeToSign: " << src.getGradeToSign() << ", gradeToExec: " << src.getGradeToExec();
    return out;
}