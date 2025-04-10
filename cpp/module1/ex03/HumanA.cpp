#include "HumanA.hpp"

void HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string humanName, Weapon &weaponClub)
	: name(humanName), weapon(weaponClub) {}
