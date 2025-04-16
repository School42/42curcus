#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal("WrongCat") {
	this->type = name;
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy Contstructor called" << std::endl;
	this->type = other.getType();
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCats meow" << std::endl;
}
