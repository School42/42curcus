#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;
	public:
		Cat();
		Cat(std::string);
		~Cat();
		Cat(const Cat &other);
		using Animal::operator=;
		void makeSound(void) const;
		std::string getIdea(int Index) {return this->brain->getIdea(Index);}
};

#endif