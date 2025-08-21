#include "PresidentialPardomForm.hpp"

PresidentialPardomForm::PresidentialPardomForm() : AForm("PresidentialPardomForm", 25, 5), target("Default") {
	std::cout << "PresidentialPardomForm default constructor called" << std::endl;
}

PresidentialPardomForm::PresidentialPardomForm(std::string const &target) : AForm("PresidentialPardomForm", 25, 5), target(target) {
	std::cout << "PresidentialPardomForm constructor called" << std::endl;
}

PresidentialPardomForm::~PresidentialPardomForm() {
	std::cout << "PresidentialPardomForm destructor called" << std::endl;
}

PresidentialPardomForm::PresidentialPardomForm(PresidentialPardomForm const &other) : AForm(other) {
	std::cout << "PresidentialPardomForm copy constructor called" << std::endl;
	this->target = other.target;
}

PresidentialPardomForm &PresidentialPardomForm::operator=(PresidentialPardomForm const &other) {
	std::cout << "PresidentialPardomForm assignation operator called" << std::endl;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void	PresidentialPardomForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > 150)
			throw AForm::GradeTooLowException();
		if (executor.getGrade() < 0)
			throw AForm::GradeTooHighException();
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}