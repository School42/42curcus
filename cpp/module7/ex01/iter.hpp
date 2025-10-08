#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F func) {
	if (array == NULL || func == NULL || length <= 0)
		return ;
	for (size_t i = 0; i < length; ++i)
		std::cout << func(array[i]) << " ";
	std::cout << std::endl;
}

template <typename T> T printing(T &a) {
	return a;
}

template <typename T> T increment(const T& x){
	return x + 1;
}

#endif