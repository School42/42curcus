#include "Fixed.hpp"
#include <cmath>

const int Fixed::const_integer = 8;

Fixed::Fixed() : integer(0) {}

Fixed::Fixed(const int value) {
	this->integer = value << const_integer;
}

Fixed::Fixed(const float value) {
	this->integer = roundf(value * (1 << const_integer));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		integer = other.integer;
	}
	return *this;
}

Fixed::~Fixed() {}

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

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.integer = this->integer + other.integer;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.integer = this->integer - other.integer;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long long product = static_cast<long long>(this->integer) * other.integer;
	result.integer = static_cast<int>(product >> const_integer);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	if (other.integer == 0) {
		std::cerr << "Error : Division by zero" << std::endl;
		return result;
	}
	long long dividend = (static_cast<long long>(this->integer) << const_integer);
	result.integer = static_cast<int>(dividend / other.integer);
	return result;
}

Fixed& Fixed::operator++() {
	this->integer += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	this->integer -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->integer += 1;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->integer -= 1;
	return temp;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->integer > other.integer;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->integer >= other.integer;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->integer < other.integer;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->integer <= other.integer;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->integer == other.integer;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->integer != other.integer;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}