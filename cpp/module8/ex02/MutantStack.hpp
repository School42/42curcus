#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T> stack;
		typedef typename stack::container_type::iterator iterator;
		typedef typename stack::container_type::const_iterator const_iterator;
		typedef typename stack::container_type::reverse_iterator reverse_iterator;
		typedef typename stack::container_type::const_reverse_iterator const_reverse_iterator;
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_iterator cbegin();
		const_iterator cend();
		const_reverse_iterator crbegin();
		const_reverse_iterator crend();
};

#endif