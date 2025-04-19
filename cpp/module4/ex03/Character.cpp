#include "Character.hpp"

Character::Character() : ICharacter() {
	std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
	this->name = "Robot";
	this->size = 0;
}

Character::Character(std::string Name) : ICharacter(Name), name(Name), size(0) {
	std::cout << "Character Constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : ICharacter(other) {
	std::cout << "Character Copy Constructor called" << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4 ; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
		this->name = other.getName();
		this->size = 0;
		for (int i = 0; i < 4; i++) {
			if (other.inventory[i]) {
				this->inventory[i] = other.inventory[i]->clone();
				this->size++;
			}
		}
	}
	return *this;
}


Character::~Character() {
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < this->size; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }
	if (this->size < 4) {
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] == NULL) {
                this->inventory[i] = m;
                this->size++;
                std::cout << "Equipped " << m->getType() << " at slot " << i << std::endl;
                return;
            }
        }
    }
	else
		std::cout << "Couldn't equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
	if (!(idx >= 0 && idx < 4)) {
		std::cout << "Please set the right index" << std::endl;
		return ;
	}
	if (this->inventory[idx]) {
        std::cout << "Unequipped " << this->inventory[idx]->getType() << " from slot " << idx << std::endl;
        this->inventory[idx] = NULL;
        this->size--;
    } else {
        std::cout << "No materia equipped at slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index: " << idx << std::endl;
        return;
    }
    
    if (this->inventory[idx]) {
        this->inventory[idx]->use(target);
    } else {
        std::cout << "No materia equipped at slot " << idx << std::endl;
    }
}
