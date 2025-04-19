#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Forward.hpp"

class	Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
		int size;
	public:
		Character();
		Character(std::string);
		Character(const Character &other);
		Character &operator=(const Character &other);

		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif