#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <iterator>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
};

#endif