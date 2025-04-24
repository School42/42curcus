#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Constructor called" << std::endl;
	this->brain = new Brain("Dog");
}

Dog::Dog(std::string name) : Animal("Dog") {
	this->type = name;
	std::cout << "Dog Constructor called" << std::endl;
	this->brain = new Brain(name);
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy Contstructor called" << std::endl;
	this->type = other.getType();
	this->brain = new Brain(*(other.brain));
}

Dog &Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy Assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Dogs bark" << std::endl;
}
