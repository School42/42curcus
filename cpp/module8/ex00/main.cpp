#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
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
	std::list<int> lst = {1, 2, 3, 4, 5};
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
	std::deque<int> deq = {1, 2, 3, 4, 5};
	try {
		std::deque<int>::iterator it = easyfind(deq, 3);
		std::cout << "Deque: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::deque<int>::iterator it = easyfind(deq, 6);
		std::cout << "Deque: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	try {
		std::array<int, 5>::iterator it = easyfind(arr, 3);
		std::cout << "Array: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::array<int, 5>::iterator it = easyfind(arr, 6);
		std::cout << "Array: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}