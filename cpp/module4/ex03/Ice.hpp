#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string const &type);
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);

		std::string const & getType() const;
		
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif