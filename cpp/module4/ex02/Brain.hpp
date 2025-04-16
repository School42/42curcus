#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const std::string &type);
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		std::string getIdea(int Index);
};

#endif