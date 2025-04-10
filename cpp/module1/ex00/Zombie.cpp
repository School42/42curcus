#include "Zombie.hpp"

Zombie::Zombie(std::string zbName): name(zbName){
	std::cout << name << " is coming!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << ": is destroyed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

