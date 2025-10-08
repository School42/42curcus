#include "iter.hpp"

int main(void) {
	int arr[5] = {1, 2, 3, 4, 5};
	iter(arr, 5, &printing<int>);
	std::cout << std::endl;
	std::string arr2[3] = {"one", "two", "three"};
	iter(arr2, 3, &printing<std::string>);
	std::cout << std::endl;
	double arr3[3] = {1.1, 2.2, 3.3};
	iter(arr3, 3, &printing<double>);
	std::cout << std::endl;
	const int arr4[5] = {1, 2, 3, 4, 5};
	iter(arr4, 5, &increment<int>);
	return 0;
}