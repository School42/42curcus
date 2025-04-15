#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default Constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name) {
	std::cout << "FragTrap Constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoint(other.getEnergyPoint());
		this->setHitPoint(other.getHitPoint());
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->hitPoint <= 0 || this->energyPoint <= 0) {
		std::cout << "FragTrap " << this->getName() << " can't attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage << " points of damage! ";
	std::cout << "Energy: " << this->energyPoint << " Status: Attacked" << std::endl;
	--this->energyPoint;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap high fives Guys!!!" << std::endl;
}