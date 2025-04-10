#pragma once 
#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


class Harl
{
	private:
		void debug (void);
		void info (void);
		void warning (void);
		void error (void);
	public:
		Harl(){};
		~Harl(){};
		void complain(std::string level);
};

#endif