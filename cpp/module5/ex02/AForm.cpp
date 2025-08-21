#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm Constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other) {
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

AForm::AForm(AForm const &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &src) {
	out << src.getName() << ", is signed: " << src.getIsSigned() << ", grade to sign: " << src.getGradeToSign() << ", grade to execute: " << src.getGradeToExecute();
	return out;
}

