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
#include <cmath>

class PmergeMe
{
	private:
		template <typename T> void merge_insert(T &container, int level);
		template <typename T> void swap_pairs(T it, int level);
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void sort_list(std::list<int> &list);
		void sort_deque(std::deque<int> &deque);
		static int comps;
};

long jacobsthal_value(long n);

#endif