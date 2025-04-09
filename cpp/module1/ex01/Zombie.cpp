#include "Zombie.hpp"

Zombie::Zombie(std::string zbName): name(zbName){
	std::cout << name << " is called!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << ": is destroyed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N ; i++) {
		horde[i] = Zombie(name);
		horde[i].announce();
	}
	return &horde[0];
}