#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	this->_stack = other.getStack();
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other.getStack();
	}
	return *this;
}

std::stack<double> RPN::getStack() const { return this->_stack; }

int RPN::calculating(std::string input){
	if (this->_stack.size() < 2) {
		std::cerr << "Error: not enough operands" << std::endl;
		return 1;
	}
	double a = this->_stack.top();
	this->_stack.pop();
	double b = this->_stack.top();
	this->_stack.pop();
	if (input == "+")
		this->_stack.push(b + a);
	else if (input == "-")
		this->_stack.push(b - a);
	else if (input == "*")
		this->_stack.push(b * a);
	else if (input == "/")
		this->_stack.push(b / a);
	return 0;
}

double ft_stod(std::string str) {
	std::stringstream ss(str);
	double result;
	ss >> result;
	return result;
}

bool is_number(std::string str) {
	std::stringstream ss(str);
	double result;
	ss >> result;
	if (ss.fail())
		return false;
	return true;
}

void RPN::calculate(std::string input) {
	std::stringstream ss(input);
	std::string token;
	while (ss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (this->calculating(token) == 1)
				return;
		} else {
			if (is_number(token) == false) {
				std::cerr << "Error: invalid input : " << token << std::endl;
				return;
			}
			double num = ft_stod(token);
			if (!(num < 10)) {
				std::cerr << "Error: input too big : " << token << std::endl;
				return;
			}
			this->_stack.push(num);
		}
	}
	if (this->_stack.size() != 1) {
		std::cerr << "Error: invalid input" << std::endl;
		return;
	}
	double result = this->_stack.top();
	this->_stack.pop();
	std::cout << result << std::endl;
}