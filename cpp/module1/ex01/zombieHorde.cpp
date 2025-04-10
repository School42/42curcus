#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N ; i++) {
		horde[i].set_values(name);
		horde[i].announce();
	}
	return &horde[0];
}