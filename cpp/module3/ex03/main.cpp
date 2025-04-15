#include "DiamondTrap.hpp"

int main()
{
	std::cout << "####################################################" << std::endl;
	std::cout << "###############  Testing DiamondTrap  ##############" << std::endl;
	std::cout << "####################################################" << std::endl;

	DiamondTrap diamond("Ruby");

	std::cout << "\n---------- DiamondTrap " << diamond.getName() << " ----------" << std::endl;
	std::cout << "Hitpoints: " << diamond.getHitPoint() << " ";
	std::cout << "Energy: " << diamond.getEnergyPoint() << " ";
	std::cout << "Attack Damage: " << diamond.getAttackDamage() << " ";
	std::cout << " Status: Active" << std::endl;
	std::cout << "\nStart attacking...\n" << std::endl;

	diamond.attack("Meta Knight");
	diamond.takeDamage(15);
	diamond.beRepaired(10);
	diamond.attack("Dark Samus");
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	diamond.attack("Ridley");

	std::cout << "\nCalling whoAmI...\n" << std::endl;
	diamond.whoAmI();

	std::cout << "\nCreating copy DiamondTraps...\n" << std::endl;
	DiamondTrap diamondCopy(diamond);
	DiamondTrap diamondClone = diamond;

	std::cout << "\nCopy attacking to test duplicates...\n" << std::endl;
	diamondCopy.attack("Copy Target");
	diamondClone.attack("Clone Target");

	std::cout << "\nFights are over..." << std::endl;
	return 0;
}
