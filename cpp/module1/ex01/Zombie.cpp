#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "a zombie is coming" << std::endl;
}

void Zombie::set_values(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << name << ": is destroyed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
