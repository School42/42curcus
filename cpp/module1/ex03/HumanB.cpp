#include "HumanB.hpp"

void HumanB::attack(void) {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string humanName) : name(humanName) {}

void HumanB::setWeapon(Weapon &weaponClub) {
	this->weapon = &weaponClub;
}
