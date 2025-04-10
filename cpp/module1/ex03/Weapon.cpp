#include "Weapon.hpp"

const std::string &Weapon::getType() const {
	return (this->type);
}

void Weapon::setType(std::string name) {
	this->type = name;
}

Weapon::Weapon(std::string name) : type(name) {}