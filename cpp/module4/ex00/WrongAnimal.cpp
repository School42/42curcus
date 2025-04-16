#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string name) : type(name) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = other;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal Copy Assignament Operator called" << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return *this;
}

void WrongAnimal::set_type(const std::string &name) {
	this->type = name;
	std::cout << "WrongAnimal set_type called" << std::endl;
}
void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

const std::string& WrongAnimal::getType(void) const {
	return this->type;
}