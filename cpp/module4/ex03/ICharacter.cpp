#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter default constructor called" << std::endl;
	this->name = "Robot";
}

ICharacter::ICharacter(std::string Name) : name(Name) {
	std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other) {
	std::cout << "ICharacter copy constructor called" << std::endl;
	*this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &other) {
	std::cout << "ICharacter copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
	}
	return *this;
}
