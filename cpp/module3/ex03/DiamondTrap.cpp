#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = 50;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name), name(Name) {
	std::cout << "DiamondTrap Constructor called" << std::endl;

	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = 50;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "DiamondTrap Copy Constructor called"<< std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap Copy Assignment Operator called" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << name << ", ClapTrap name is " << ClapTrap::name << "\n";
}
