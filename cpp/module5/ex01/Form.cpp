#include "Form.hpp"

Form::Form(): name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(Form const &src): name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
	std::cout << "Form Copy constructor called" << std::endl;
	*this = src;
}

Form &Form::operator=(Form const &src) {
	std::cout << "Form Assignation operator called" << std::endl;
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

std::string Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form const &src) {
	out << src.getName() << ", is signed: " << src.getIsSigned() << ", grade to sign: " << src.getGradeToSign() << ", grade to execute: " << src.getGradeToExecute();
	return out;
}