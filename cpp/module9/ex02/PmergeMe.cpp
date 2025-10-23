#include "PmergeMe.hpp"

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& pm) { (void)pm; }

PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    (void)pm;
    return *this;
}

PmergeMe::~PmergeMe() {}

long jacob_num(long n) { 
	return ((static_cast<long>(pow(2, n)) - static_cast<long>(pow(-1, n))) / 3);
}

void PmergeMe::sort_vec(std::vector<int>& vec) { 
	merge_insert_sort<std::vector<int> >(vec, 1); 
}

void PmergeMe::sort_deque(std::deque<int>& deque)
{
    merge_insert_sort<std::deque<int> >(deque, 1);
}
