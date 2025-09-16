#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

long jacobsthal_value(long n) {
	return ((static_cast<long>(pow(2, n)) - static_cast<long>(pow(-1, n))) / 3);
}

template <typename T> T next(T it, int leap) {
	std::advance(it, leap);
	return it;
}

template <typename T> bool compare(T a, T b) { 
	PmergeMe::comps++;
	return a > b; 
}

template <typename T> void swap_pairs(T it, int level) {
	T start = next(it, -level + 1);
	T end = next(it, level);
	while (start != end) {
		std::iter_swap(start, next(start, level));
		start++;
	}
}

void PmergeMe::sort_deque(std::deque<int> &deque) {
	merge_insert(deque, 1);
}

void PmergeMe::sort_list(std::list<int> &list) {
	merge_insert(list, 1);
}

template <typename T> void PmergeMe::merge_insert(T &container, int level) {
	typedef typename T::iterator it;
	int pairs = container.size() / level;
	if (pairs < 2)
		return;

	bool is_odd = pairs % 2 == 1;
	it start = container.begin();
	it last = next(start, level * pairs); // last node
	it end = next(last, -(is_odd * level)); // second node of the last pair

	int jump = 2 * level;
	it i = start;
	while (i != end) {
		it first_node = next(i, level - 1);
		it second_node = next(i, jump - 1);
		if (compare(*second_node, *first_node)) {
			swap_pairs(first_node, level);
		}
		i = next(i, jump);
	}
	merge_insert(container, level * 2);
	std::list<it> main;
	std::list<it> pend;
	main.insert(main.end(), next(container.begin(), level - 1));
	main.insert(main.end(), next(container.begin(), level * 2 - 1));
	for (int i = 4; i <= pairs; i += 2) {
		pend.insert(pend.end(), next(container.begin(), level * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), level * i - 1));
	}
	if (is_odd) {
		pend.insert(pend.end(), next(end, level - 1));
	}

	int prev_jacob = jacobsthal_value(2);
	int inserted = 0;
	for (int j = 2; ; j++) {
		int curr_jacob = jacobsthal_value(j + 1);
		int diff = curr_jacob - prev_jacob;
		int offset = 0;
		if (diff > static_cast<int>(pend.size()))
			break;
		int count = diff;
		typename std::list<it>::iterator pend_it = next(pend.begin(), diff - 1);
		typename std::list<it>::iterator bound_it = next(main.begin(), curr_jacob + inserted);
		while (count) {
			typename std::list<it>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, compare<it>);
			typename std::list<it>::iterator inserted_it = main.insert(idx, *pend_it);
			count--;
			pend_it = pend.erase(pend_it);
			pend_it = next(pend_it, -1);
			offset += (inserted_it - main.begin()) == curr_jacob + inserted;
			bound_it = next(main.begin(), curr_jacob + inserted - offset);
		}
		prev_jacob = curr_jacob;
		inserted += diff;
		offset = 0;
	}

	for (ssize_t k = pend.size() - 1; k >= 0; k--) {
		typename std::list<it>::iterator curr_pend = next(pend.begin(), k);
		typename std::list<it>::iterator curr_bound = next(main.begin(), main.size() - pend().size() + k + is_odd);
		typename std::list<it>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, compare<it>);
		main.insert(idx, *curr_pend);
	}

	std::list<int> copy;
	copy.reverse(container.size());
	for (typename std::list<it>::iterator it = main.begin(); it != main.end(); it++) {
		for (int i = 0; i < level; i++) {
			it pair_start = *it;
			std::advance(pair_start, -level + i + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}
	it it1 = container.begin();
	for (typename std::list<int>::iterator it2 = copy.begin(); it2 != copy.end(); it2++) {
		*it1 = *it2;
		it1++;
	}
}