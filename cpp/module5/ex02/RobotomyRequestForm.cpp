#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	this->target = "default";
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {
	this->target = other.target;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > 150)
			throw AForm::GradeTooLowException();
		if (executor.getGrade() < 0)
			throw AForm::GradeTooHighException();
		std::cout << "* DRILL NOISES *" << std::endl;
		std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}