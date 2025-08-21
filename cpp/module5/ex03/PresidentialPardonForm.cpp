#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	this->target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
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