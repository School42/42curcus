#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main(void) {
	std::cout << "first test" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "second test" << std::endl;
	{
		MutantStack<std::string> strstack;
		strstack.push("Hello");
		strstack.push("World");
		strstack.push("!");
		strstack.push("World");
		strstack.push("Hello");
		strstack.push("Hi");
		strstack.push("Rick");
		// std::cout << strstack.top() << std::endl;
		// strstack.pop();
		// std::cout << strstack.size() << std::endl;
		strstack.push("!");
		MutantStack<std::string>::iterator it = strstack.begin();
		MutantStack<std::string>::iterator ite = strstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "###############" << std::endl;
		MutantStack<std::string>::reverse_iterator itr = strstack.rbegin();
		MutantStack<std::string>::reverse_iterator tmp = itr;
		for (int i = 0; i < 3; i++) {
			std::cout << *itr << std::endl;
			*itr = "Tauk";
			++itr;
		}
		std::cout << "###############" << std::endl;
		itr = tmp;
		for (int i = 0; i < 3; i++) {
			std::cout << *itr << std::endl;
			++itr;
		}
		std::cout << "###############" << std::endl;
		MutantStack<std::string>::const_iterator citr = strstack.cbegin();
		try {
			for (int i = 0; i < 3; i++) {
				std::cout << *citr << std::endl;
				// *citr = "Good";
				++citr;
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::stack<std::string> s(strstack);
	}
	return 0;
}