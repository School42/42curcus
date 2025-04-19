#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Default Constructor called" << std::endl;
}


Cure::~Cure() {
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
