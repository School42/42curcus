#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <sstream>

int main()
{
    std::cout << "===== BASIC FUNCTIONALITY TEST =====" << std::endl;
    
    Animal* dog = new Dog("Rex");
    Animal* cat = new Cat("Whiskers");
    
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    std::cout << "\n===== BRAIN IDEAS TEST =====" << std::endl;
    
    Dog directDog("Buddy");
    Cat directCat("Felix");
    
    std::cout << "Dog's idea: " << directDog.getIdea(0) << std::endl;
    std::cout << "Cat's idea: " << directCat.getIdea(1) << std::endl;
    
    std::cout << "\n===== COPY TEST =====" << std::endl;
    
    Dog originalDog("Original");
    Dog copiedDog = originalDog;
    
    std::cout << "Original dog type: " << originalDog.getType() << std::endl;
    std::cout << "Copied dog type: " << copiedDog.getType() << std::endl;
    std::cout << "Original dog idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied dog idea: " << copiedDog.getIdea(0) << std::endl;
    
    std::cout << "\n===== DYNAMIC ARRAY TEST =====" << std::endl;
    
    int number;
    std::cout << "Enter the count of animals (1-100): ";
    std::string countStr;
    std::getline(std::cin, countStr);
    std::stringstream(countStr) >> number;
    
    if (number <= 0 || number > 100) {
        std::cout << "Please enter a number between 1 and 100" << std::endl;
        return 1;
    }
    
    Animal* animals[number];

    for (int i = 0; i < number; i++) {
        if (i % 2 == 0) {
            animals[i] = new Cat();
            std::cout << "Created Cat #" << i << std::endl;
        } else {
            animals[i] = new Dog();
            std::cout << "Created Dog #" << i << std::endl;
        }
    }
    
    for (int i = 0; i < number; i++) {
        std::cout << "Animal #" << i << " (" << animals[i]->getType() << ") says: ";
        animals[i]->makeSound();
        
        if (animals[i]->getType() == "Cat") {
            Cat* catPtr = dynamic_cast<Cat*>(animals[i]);
            if (catPtr) {
                std::cout << "  Cat's idea: " << catPtr->getIdea(0) << std::endl;
            }
        } else if (animals[i]->getType() == "Dog") {
            Dog* dogPtr = dynamic_cast<Dog*>(animals[i]);
            if (dogPtr) {
                std::cout << "  Dog's idea: " << dogPtr->getIdea(0) << std::endl;
            }
        }
    }
    
    for (int i = 0; i < number; i++) {
        delete animals[i];
    }
    
    std::cout << "\n===== WRONG ANIMAL TEST =====" << std::endl;
    
    WrongAnimal* wrongCat = new WrongCat("WrongKitty");
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();
    
    delete wrongCat;
    
    return 0;
}