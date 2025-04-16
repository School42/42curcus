#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal constructor called" << std::endl;
}
Animal::Animal(std::string name) : type(name) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = other;
}
Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal Copy Assignament Operator called" << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return *this;
}

void Animal::set_type(const std::string &name) {
	this->type = name;
	std::cout << "Animal set_type called" << std::endl;
}
void Animal::makeSound() const {
	std::cout << "Animal makes a sound" << std::endl;
}

const std::string& Animal::getType(void) const {
	return this->type;
}