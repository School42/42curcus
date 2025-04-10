#include "Zombie.hpp"
#include <climits>
#include <sstream>

int main(){
	std::cout << "Enter the number of zombies: ";
	std::string numZom;
	std::getline(std::cin, numZom);
	int N;
	std::stringstream ss(numZom);
	ss >> N;
	if (ss.fail() || N <= 0 || N > INT_MAX) {
		std::cout << "Please enter valid input!" << std::endl;
		return (1);
	}
	if (N > 100){
		std::cout << "Dude, don't count the zombies! Just run!!!" << std::endl;
		return (0);
	}
	Zombie* firstZombie = zombieHorde(N, "zombie777");
	delete[] firstZombie;
	return (0);
}