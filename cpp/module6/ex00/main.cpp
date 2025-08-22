#include "ScalarConverter.hpp"
#include <typeinfo>

int main(int argc, char **argv) {
	ScalarConverter converter;
	if (argc == 2) {
		converter.convert(argv[1]);
	} else {
		std::cout << "Wrong number of arguments" << std::endl;
	}
	return 0;
}