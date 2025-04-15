#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
	std::cout << "ScavTrap Constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
	if (this == &other)
		return *this;
	this->setName(other.getName());
	this->setAttackDamage(other.getAttackDamage());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << getName() << " is now on Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->hitPoint <= 0 || this->energyPoint <= 0) {
		std::cout << "ScavTrap " << this->getName() << " can't attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage << " points of damage! ";
	std::cout << "Energy: " << this->energyPoint << " Status: Attacked" << std::endl;
	--this->energyPoint;
}


