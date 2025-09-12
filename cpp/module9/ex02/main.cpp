#include "PmergeMe.hpp"

bool is_positive_number(std::string str) {
	if (str[0] == '-')
		return false;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!std::isdigit(str[i]))
			return false;
	}
	std::stringstream ss(str);
	long result;
	ss >> result;
	if (result <= 0)
		return false;
	std::cout << result << std::endl;
	if (result > std::numeric_limits<int>::max())
		return false;
	return true;
}

std::list<std::string> split(std::string str, char delimeter) {
	std::list<std::string> result;
	std::string token;
	size_t start = 0;
	while (str[start] == delimeter)
		start++;
	while (start < str.length()) {
		size_t end = str.find(delimeter, start);
		if (end == std::string::npos)
			end = str.length();
		token = str.substr(start, end - start);
		result.push_back(token);
		start = end + 1;
		while (start < str.length() && str[start] == delimeter)
			start++;
	}
	return result;
}

bool validateArg(std::string arg) {
	std::list<std::string> tokens = split(arg, ' ');
	if (tokens.empty())
		return false;
	std::list<std::string>::iterator it = tokens.begin();
	while (it != tokens.end()) {
		if (!is_positive_number(*it))
			return false;
		it++;
	}
	return true;
}

bool validateInput(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		if (!validateArg(av[i]))
			return false;
	}
	return true;
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Please run this program as : ./PmergeMe <numbers>" << std::endl;
		return 1;
	}
	if (!validateInput(ac, av)) {
		std::cerr << "Error\n" << "Please enter only positive int numbers!!!" << std::endl;
		return 1;
	}
	return 0;
}