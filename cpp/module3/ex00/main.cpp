#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Mario("Mario");
	
	Mario.setAttackDamage(3);
	std::cout << "\n---------- ClapTrap " << Mario.getName() << " ----------" << std::endl;
	std::cout << "Hitpoints: " << Mario.getHitPoint() << " ";
	std::cout << "Energy: " << Mario.getEnergyPoint() << " ";
	std::cout << "Attack Damage: " << Mario.getAttackDamage() << " ";
	std::cout << " Status: Active" << std::endl;
	std::cout << "\nStart attacking...\n" << std::endl;

	Mario.attack("Dry Bowser");
	Mario.attack("Shadow Queen");
	Mario.takeDamage(3);
	Mario.takeDamage(4);
	Mario.beRepaired(100);
	Mario.attack("Bowser");
	Mario.attack("King Boo");
	Mario.attack("Kamek");
	Mario.attack("Fawful");

	std::cout << "\nFights are over..." << std::endl;
}