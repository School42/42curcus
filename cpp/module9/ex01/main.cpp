#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Please run this program as : ./RPN <expression>" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.calculate(av[1]);
	return 0;
}