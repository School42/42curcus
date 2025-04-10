#include "Fixed.hpp"
#include <cmath>

const int Fixed::const_integer = 8;

Fixed::Fixed() : integer(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->integer = value << const_integer;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->integer = roundf(value * (1 << const_integer));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		integer = other.integer;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return (float)integer / (1 << const_integer);
}

int Fixed::toInt( void ) const {
	return integer >> const_integer;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
