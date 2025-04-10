#pragma once 
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		const std::string &getType() const;
		void setType(std::string name);
		Weapon(std::string);
		Weapon(){};
		~Weapon(){};
};

#endif