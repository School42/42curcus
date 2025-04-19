#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    Character* original = new Character("original");
    tmp = src->createMateria("ice");
    original->equip(tmp);
    
    Character* copy = new Character(*original);
    std::cout << "Testing copy - original uses materia on bob:" << std::endl;
    original->use(0, *bob);
    std::cout << "Testing copy - copy uses materia on bob:" << std::endl;
    copy->use(0, *bob);

    delete copy;
    delete original;
    delete bob;
    delete me;
    delete src;
    
    return 0;
}