#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat << std::endl;
		Form form("Form", 1, 1);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat << std::endl;
		Form form("Form", 1, 151);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat << std::endl;
		Form form("Form", 151, 1);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat << std::endl;
		Form form("Form", 0, 151);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Bureaucrat("Bureaucrat", 10);
		std::cout << Bureaucrat << std::endl;
		Form form("Form", 5, 5);
		std::cout << form << std::endl;
		Bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}