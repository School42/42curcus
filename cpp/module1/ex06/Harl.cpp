#include "Harl.hpp"

void Harl::debug (void) {
	std::cout << GREEN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << RESET << std::endl;
}

void Harl::info (void) {
	std::cout << BLUE << "[ INFO ]" << RESET << std::endl;
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET << std::endl;
}

void Harl::warning (void) {
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << RESET << std::endl;
}

void Harl::error (void) {
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << RED << "This is unacceptable! I want to speak to the manager now.\n" << RESET << std::endl;
}

void Harl::complain(std::string level) {
	std::string number[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl = -1;
	for (int i = 0; i < 4; i++) {
		if (number[i] == level) {
			lvl = i;
			break;
		}
	}
	switch (lvl)
	{
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case 1:
			this->info();
			this->warning();
			this->error();
			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}