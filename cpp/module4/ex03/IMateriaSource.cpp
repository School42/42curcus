#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
	std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other) {
	std::cout << "IMateriaSource copy constructor called" << std::endl;
	*this = other;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other) {
	std::cout << "IMateriaSource copy assignment operator called" << std::endl;
	(void) other;
	return *this;
}

