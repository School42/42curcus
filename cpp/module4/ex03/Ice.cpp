#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Default Constructor called" << std::endl;
}


Ice::~Ice() {
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "Ice Copy Constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
