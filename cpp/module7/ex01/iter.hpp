#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *arr, const int len, void (*f)(T &)) {
	if (len == 0 || arr == NULL || f == NULL)
		return;
	for (int i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T> void printing(T &a) {
	std::cout << a << " ";
}

template <typename T> void singing(const T &a) {
	std::cout << "La la la " << a << std::endl;
}

#endif