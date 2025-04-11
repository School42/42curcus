#include "Harl.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Please run this program as : ./harlFilter <complain>" << std::endl;
		return 1;
	}
	Harl complain;
	std::string level = av[1];
	complain.complain(level);
	return 0;
}