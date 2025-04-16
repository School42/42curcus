#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal("Dog") {
	this->type = name;
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy Contstructor called" << std::endl;
	this->type = other.getType();
}

void Dog::makeSound(void) const {
	std::cout << "Dogs bark" << std::endl;
}
