#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int integer;
		static const int const_integer;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif