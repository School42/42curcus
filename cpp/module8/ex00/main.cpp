#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;
	for (int i = 0; i < 5; i++){
		vec.push_back(i + 1);
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Vector: " <<  *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Vector: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::list<int> lst;
	for (int i = 0; i < 5; i++){
		lst.push_back(i + 1);
	}
	try {
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "List: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator it = easyfind(lst, 6);
		std::cout << "List: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}