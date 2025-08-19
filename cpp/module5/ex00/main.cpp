#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("bureaucrat", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b("bureaucrat", 151);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}