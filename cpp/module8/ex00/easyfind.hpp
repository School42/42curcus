#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <exception>
#include <iostream>

class CustomException : public std::exception {
	public:
		const char *what() const throw() {
			return "Value not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	const typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw CustomException();
	return it;
}

#endif