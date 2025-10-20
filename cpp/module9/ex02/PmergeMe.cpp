#include "PmergeMe.hpp"

int PmergeMe::comps = 0;

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { 
    *this = other; 
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void)other;
    return *this;
}

long jacobsthal_value(long n) {
    return ((static_cast<long>(pow(2, n)) - static_cast<long>(pow(-1, n))) / 3);
}

void PmergeMe::sort_deque(std::deque<int> &deque) {
    merge_insert(deque, 1);
}

void PmergeMe::sort_list(std::list<int> &list) {
    merge_insert(list, 1);
}