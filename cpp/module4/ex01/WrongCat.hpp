#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string);
		~WrongCat();
		WrongCat(const WrongCat &other);
		using WrongAnimal::operator=;
		void makeSound(void) const;
};

#endif