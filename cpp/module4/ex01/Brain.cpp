#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default Constructor Called" << std::endl;
	for (int i = 0; i < 100 ; i++) {
		this->ideas[i] = "Good Idea ";
	}
}

Brain::Brain(const std::string &type) {
	std::cout << "Brain Default Constructor Called" << std::endl;
	for (int i = 0; i < 100 ; i++) {
		this->ideas[i] = type + "'s Good Idea ";
	}
}


Brain::~Brain() {
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	for (int i = 0; i < 100 ; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100 ; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(int Index) {
	if (Index < 0 || Index >= 100) {
		return NULL;
	}
	return this->ideas[Index];
}