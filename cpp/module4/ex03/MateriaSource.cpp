#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : size(0) {
	std::cout << "MateriaSource Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other), size(0) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
        this->materia[i] = NULL;
    }
    
    for (int i = 0; i < 4; i++) {
        if (other.materia[i]) {
            this->materia[i] = other.materia[i]->clone();
            this->size++;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
            if (this->materia[i]) {
                delete this->materia[i];
                this->materia[i] = NULL;
            }
        }
        
        this->size = 0;
        for (int i = 0; i < 4; i++) {
            if (other.materia[i]) {
                this->materia[i] = other.materia[i]->clone();
                this->size++;
            }
        }
	}
	return *this;
}


MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0 ; i < 4 ; i++) {
		if (this->materia[i])
			delete this->materia[i];
	}
}

void MateriaSource::learnMateria(AMateria *m){
	if (!m) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }
    
    if (this->size >= 4) {
        std::cout << "Can't learn any more materias, storage is full" << std::endl;
        delete m;
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (!this->materia[i]) {
                this->materia[i] = m;
                this->size++;
                std::cout << "Learned materia: " << m->getType() << std::endl;
                return;
            }
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4 && this->materia[i]; i++) {
        if (type == this->materia[i]->getType()) {
            return this->materia[i]->clone();
        }
    }
    std::cout << "Unknown materia type: " << type << std::endl;
    return NULL;
}

void MateriaSource::printMateria(void) const {
	if (size == 0) {
        std::cout << "No materias learned yet" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->materia[i]) {
            std::cout << "Materia " << i << ": " << this->materia[i]->getType() << std::endl;
        }
    }
}
