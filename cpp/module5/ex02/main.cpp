#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	try {
		Bureaucrat	bob("Bob", 1);
		std::cout << bob << std::endl;
		ShrubberyCreationForm	form("home");
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat	bob("Bob", 1);
		std::cout << bob << std::endl;
		RobotomyRequestForm	form("home");
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat	bob("Bob", 1);
		std::cout << bob << std::endl;
		PresidentialPardonForm	form("home");
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat	bob("Bob", 20);
		std::cout << bob << std::endl;
		PresidentialPardonForm	form("home");
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;
		PresidentialPardonForm	form("home");
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}