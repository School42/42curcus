#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Constructor called" << std::endl;
	this->brain = new Brain("Cat");
}

Cat::Cat(std::string name) : Animal("Cat") {
	this->type = name;
	this->brain = new Brain(name);
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat Copy Contstructor called" << std::endl;
	this->type = other.getType();
	this->brain = new Brain(*(other.brain));
}

Cat &Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Cats meow" << std::endl;
}
