#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		unsigned int hitPoint;
		unsigned int energyPoint;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);

		unsigned int getHitPoint(void) const;
		unsigned int getAttackDamage(void) const;
		unsigned int getEnergyPoint(void) const;
		const std::string& getName(void) const;

		void setName(const std::string &name);
		void setHitPoint(unsigned int hitPoint);
		void setAttackDamage(unsigned int attackDamage);
		void setEnergyPoint(unsigned int energyPoint);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif