#include "Zombie.hpp"

int main() {
	Zombie* zombie = NULL;
	zombie = zombie->newZombie("zombie 1");
	zombie->randomChump("zombie 2");
	delete zombie;
	return 0;
}