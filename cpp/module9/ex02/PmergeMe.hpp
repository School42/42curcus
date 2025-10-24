#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <deque>
#include <vector>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <set>
#include <cmath>
#include <deque>

#ifndef EXPLANATION
#define EXPLANATION 0
#endif

// example explanation: ./PmergeMe 3 5 2 1 4 8 7 6 9 11 10 13 12

class PmergeMe
{
	private:
		template <typename T> void merge_insert_sort(T& container, int level);
		template <typename T> void swap(T it, int level);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& pm);
		PmergeMe& operator=(const PmergeMe& pm);
		~PmergeMe();
		void sort_vec(std::vector<int>& vec);
		void sort_deque(std::deque<int>& deque);
		static int nbr_of_comps;
};

long jacob_num(long n);

template <typename T> bool compare(T lv, T rv) {
	PmergeMe::nbr_of_comps++;
	return *lv < *rv;
}

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T> void PmergeMe::swap(T it, int level)
{
    T start = next(it, -level + 1);
    T end = next(start, level);
    while (start != end)
    {
        std::iter_swap(start, next(start, level));
        start++;
    }
}

template <typename T> void PmergeMe::merge_insert_sort(T& container, int level)
{
    typedef typename T::iterator It;

    int pairs = container.size() / level;
    if (pairs < 2)
        return;
    bool is_odd = pairs % 2 == 1;
	if (EXPLANATION) {
		std::cout << "########################################################" << std::endl;
		std::cout << "Level: " << level << " Before : (";
		int count = 0;
		for (int i = 0; i < (int)container.size(); i++) {
			std::cout << container[i];
			count++;
			if (count == level) {
				std::cout << ") ";
				if (i != (int)container.size() - 1) {
					std::cout << "(";
				}
				count = 0;
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
    It start = container.begin();
    It last = next(container.begin(), level * (pairs));
    It end = next(last, -(is_odd * level));
	if (EXPLANATION) {
		std::cout << " pairs: " << pairs << " is_odd: " << is_odd << " start: " << *start << " end: " << *end << " last: " << *last << std::endl;
	}
    int jump = 2 * level;
    for (It it = start; it != end; it = next(it, jump))
    {
        It this_pair = next(it, level - 1);
        It next_pair = next(it, level * 2 - 1);
        if (compare(next_pair, this_pair))
        {
			if (EXPLANATION) {
				std::cout << "swap: " << *this_pair << " " << *next_pair << std::endl;
			}
            swap(this_pair, level);
        }
    }
    merge_insert_sort(container, level * 2);
	if (EXPLANATION) {
		std::cout << "Level: " << level << " After : (";
		int count = 0;
		for (int i = 0; i < (int)container.size(); i++) {
			std::cout << container[i];
			count++;
			if (count == level) {
				std::cout << ") ";
				if (i != (int)container.size() - 1) {
					std::cout << "(";
				}
				count = 0;
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

    std::vector<It> main;
    std::vector<It> pend;

    main.insert(main.end(), next(container.begin(), level - 1));
    main.insert(main.end(), next(container.begin(), level * 2 - 1));

    for (int i = 4; i <= pairs; i += 2)
    {
        pend.insert(pend.end(), next(container.begin(), level * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), level * i - 1));
    }
    if (is_odd)
    {
        pend.insert(pend.end(), next(end, level - 1));
    }

	if (EXPLANATION) {
		std::cout << std::endl;
		std::cout << "main: ";
		for (int i = 0; i < (int)main.size(); i++){
			std::cout << *main[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "pend: ";
		for (int i = 0; i < (int)pend.size(); i++)
			std::cout << *pend[i] << " ";
		std::cout << "\n" << std::endl;
	}

    /* Insert the pend into the main in the order determined by the
       Jacobsthal numbers. in order: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.*/

    int prev_jacobsthal = jacob_num(2);
    int inserted_numbers = 0;
    for (int k = 2;; k++)
    {
        int curr_jacobsthal = jacob_num(k + 1);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
        if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<It>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
        typename std::vector<It>::iterator bound_it =
            next(main.begin(), curr_jacobsthal + inserted_numbers);
		if (EXPLANATION) {
			std::cout << "curr_jacobsthal: " << curr_jacobsthal << " jacobsthal_diff: " << jacobsthal_diff << " nbr_of_times: " << nbr_of_times << "\npend_it: " << *(*pend_it);
			if (curr_jacobsthal + inserted_numbers < (int)main.size()) {
				std::cout << " bound_it: " << *(*bound_it);
			}
			std::cout << std::endl;
		}
        while (nbr_of_times)
        {
            typename std::vector<It>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, compare<It>);
            typename std::vector<It>::iterator inserted = main.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
			if (EXPLANATION) {
				if (nbr_of_times > 0) {
					std::cout << " pend_it: " << *(*pend_it);
					if (curr_jacobsthal + inserted_numbers - offset < (int)main.size()) {
						std::cout << " bound_it: " << *(*bound_it);
					}
				}
				std::cout << std::endl;
			}
        }
		if (EXPLANATION) {
			std::cout << std::endl;
			std::cout << "main: ";
			for (int i = 0; i < (int)main.size(); i++)
				std::cout << *main[i] << " ";
			std::cout << std::endl;
			std::cout << "pend: ";
			for (int i = 0; i < (int)pend.size(); i++)
				std::cout << *pend[i] << " ";
			std::cout << "\n" << std::endl;
		}
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
		offset = 0;
    }

    /* Insert the remaining elements in the reversed order. */
    for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        typename std::vector<It>::iterator curr_pend = next(pend.begin(), i);
        typename std::vector<It>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<It>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, compare<It>);
		if (EXPLANATION) {
			if (i > 0) {
				std::cout << " curr_pend: " << *(*curr_pend);
			}
			if ((int)main.size() - (int)pend.size() + (int)i + (int)is_odd < (int)main.size()) {
				std::cout << " curr_bound: " << *(*curr_bound);
			}
			if (i > 0) {
				std::cout << " idx: " << *(*idx);
			}
			std::cout << std::endl;
		}
        main.insert(idx, *curr_pend);
		pend.erase(curr_pend);
    }
	if (EXPLANATION) {
		std::cout << std::endl;
		std::cout << "Final: " << std::endl;
		std::cout << "main: ";
		for (int i = 0; i < (int)main.size(); i++)
			std::cout << *main[i] << " ";
		std::cout << std::endl;
		std::cout << "pend: ";
		for (int i = 0; i < (int)pend.size(); i++)
			std::cout << *pend[i] << " ";
		std::cout << "\n" << std::endl;
	}

    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<It>::iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < level; i++)
        {
            It pair_start = *it;
            std::advance(pair_start, -level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    It container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}
#endif
