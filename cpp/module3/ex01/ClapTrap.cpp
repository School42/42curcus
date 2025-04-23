#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called!" << std::endl;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string objName)
	: name(objName), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << "Constructor called by : " << objName << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called!" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoint(other.getEnergyPoint());
		this->setHitPoint(other.getHitPoint());
	}
	return *this;
}

void ClapTrap::setName(const std::string &name) {
	this->name = name;
}

void ClapTrap::setHitPoint(unsigned int hitPoint) {
	this->hitPoint = hitPoint;
}

void ClapTrap::setEnergyPoint(unsigned int energyPoint) {
	this->energyPoint = energyPoint;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage = attackDamage;
}

unsigned int ClapTrap::getHitPoint(void) const{ return this->hitPoint;}

unsigned int ClapTrap::getAttackDamage(void) const{ return this->attackDamage;}

unsigned int ClapTrap::getEnergyPoint(void) const{ return this->energyPoint;}

const std::string& ClapTrap::getName(void) const{ return this->name;}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint == 0 || this->hitPoint == 0)
	{
		std::cout << "<ClapTrap " << this->name << " cannot attack. ";
		std::cout << "Energy: " << this->energyPoint << " HP: " << this->hitPoint << " Status: Exhausted>" << std::endl;
	}
	else
	{
		this->energyPoint -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target;
		std::cout << ", causing " << this->attackDamage << " points of damage! ";
		std::cout << "Energy: " << this->energyPoint << " Status: Attacked" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint == 0)
	{
		std::cout << "<ClapTrap " << this->name << " is already at 0 HP!>" << std::endl;
		return;
	}
	if (amount >= this->hitPoint)
		this->hitPoint = 0;
	else
		this->hitPoint -= amount;

	std::cout << "<ClapTrap " << this->name << " got " << amount << " points of damage!>";
	std::cout << " hitPoint: " << this->hitPoint << " Status: Damaged" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint == 0 || this->hitPoint == 0)
	{
		std::cout << "<ClapTrap " << this->name << " cannot repair. ";
		std::cout << "Energy: " << this->energyPoint << " HP: " << this->hitPoint << " Status: Exhausted>" << std::endl;
	}
	else if (this->hitPoint + amount >= 100){
		if (this->hitPoint < 100) {
			this->energyPoint -= 1;
			this->hitPoint = 100;
		}
		std::cout << "<ClapTrap " << this->name << " cannot regain HP more than 100. ";
		std::cout << "Energy: " << this->energyPoint << " HP: " << this->hitPoint << " Status: Fully Repaired>" << std::endl;
	}
	else
	{
		this->energyPoint -= 1;
		this->hitPoint += amount;
		std::cout << "<ClapTrap " << this->name << " got repaired by " << amount << " points!>";
		std::cout << " hitPoint: " << this->hitPoint << " Energy: " << this->energyPoint << " Status: Repaired" << std::endl;
	}
}