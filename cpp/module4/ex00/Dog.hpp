#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(std::string);
		~Dog();
		Dog(const Dog &other);
		using Animal::operator=;
		void makeSound(void) const;
};

#endif