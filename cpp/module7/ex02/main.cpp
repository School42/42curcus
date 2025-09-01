#include "Array.hpp"
#include "Array.tpp"

int main(void) {
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i;
	Array<int> intArray2(intArray);
	Array<int> intArray3;
	intArray3 = intArray;

	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0; i < intArray2.size(); i++)
		std::cout << intArray2[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0; i < intArray3.size(); i++)
		std::cout << intArray3[i] << " ";
	std::cout << std::endl;
	return 0;
}
