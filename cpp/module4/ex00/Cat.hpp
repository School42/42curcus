#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(std::string);
		~Cat();
		Cat(const Cat &other);
		using Animal::operator=;
		void makeSound(void) const;
};

#endif