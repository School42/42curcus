#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
	private:
		std::stack<double> _stack;
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN &operator=(const RPN &other);
		void calculate(std::string input);
		int calculating(std::string input);
		std::stack<double> getStack() const;
};

#endif