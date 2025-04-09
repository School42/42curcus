#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name){
	Zombie* temp = new Zombie(name);
	temp->announce();
	return (temp);
}