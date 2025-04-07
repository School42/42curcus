#include <iostream>
#include <cctype>
#include <string>

std::string toUpperCase(const std::string& str) {
	std::string result;
	for (int i = 0; str[i] != '\0'; ++i) {
		result += std::toupper(str[i]);
	}
	return result;
}

int main(int ac, char* av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++) {
		std::cout << toUpperCase(av[i]);
	}
	std::cout << std::endl;
	return (0);
}