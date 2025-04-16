#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string);
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		void set_type(const std::string &name);
		virtual void makeSound() const = 0;
		const std::string& getType(void) const;
};

#endif