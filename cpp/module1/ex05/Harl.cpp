#include "Harl.hpp"

void Harl::debug (void) {
	std::cout << GREEN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void Harl::info (void) {
	std::cout << BLUE << "[ INFO ]" << RESET << std::endl;
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void Harl::warning (void) {
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void Harl::error (void) {
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level) {
	std::string number[] = {"debug", "info", "warning", "error"};
	int lvl = -1;
	for (int i = 0; i < 4; i++) {
		if (number[i] == level) {
			lvl = i;
			break;
		}
	}
	void    (Harl::*funcPtr)(void) = NULL;
   	void    (Harl::*arrayPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	if (lvl != -1){
		funcPtr = arrayPtr[lvl];
		(this->*funcPtr)();
		return;
	}
	std::cerr << "Please enter valid input!!!" << std::endl;
}