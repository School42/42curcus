#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
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
	Mario.beRepaired(10);
	Mario.attack("Bowser");
	Mario.attack("King Boo");
	Mario.attack("Kamek");
	Mario.attack("Fawful");

	std::cout << "####################################################" <<std::endl << std::endl;

	ScavTrap ScavA("Robert");
	ScavA.guardGate();
	ScavA.attack("Pigeon");
	ScavA.takeDamage(10);

	ScavTrap ScavB(ScavA);
	ScavB.beRepaired(5);
	ScavB.beRepaired(1);

	ScavTrap ScavC = ScavA;
	ScavC.takeDamage(100);
	ScavC.takeDamage(100);
	ScavC.attack("Perry");

	std::cout << "####################################################" <<std::endl << std::endl;

	FragTrap FragA("Robert");
	FragA.highFivesGuys();
	FragA.attack("Pigeon");
	FragA.takeDamage(10);

	FragTrap FragB(FragA);
	FragB.beRepaired(5);
	FragB.beRepaired(1);

	FragTrap FragC = FragA;
	FragC.takeDamage(100);
	FragC.takeDamage(100);
	FragC.attack("Perry");

	std::cout << "\nFights are over..." << std::endl;
	return 0;
}