#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal("Cat") {
	this->type = name;
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat Copy Contstructor called" << std::endl;
	this->type = other.getType();
}

void Cat::makeSound(void) const {
	std::cout << "Cats meow" << std::endl;
}
