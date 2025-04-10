#include <iostream>
#include <string>

int main(){
	std::string sample = "HI THIS IS BRAIN";
	std::string *stringPTR = &sample;
	std::string &stringREF = sample;
	std::cout << "The memory address of the string variable : " << &sample << std::endl;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;
	std::cout << "The value of the string variable : " << sample << std::endl;
	std::cout << "The value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed by stringREF : " << stringREF << std::endl;
	return 0; 
}