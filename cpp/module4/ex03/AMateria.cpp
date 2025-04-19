#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("") {
	std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)  {
	std::cout << "AMateria Constructor called" << std::endl;
	this->type = type;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->type = other.getType();
	}
	return *this;
}


std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target){
	std::cout << target.getName() << " uses a meterial" << std::endl;
}