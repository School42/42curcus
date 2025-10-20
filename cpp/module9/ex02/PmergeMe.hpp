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
    template <typename T> 
    void merge_insert(T &container, int level);
    
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

template <typename T> 
T next(T it, int leap) {
    std::advance(it, leap);
    return it;
}

template <typename T> 
void swap_pairs(T it, int level) {
    T start = next(it, -level + 1);
    T end = next(it, level);
    while (start != end) {
        std::iter_swap(start, next(start, level));
        ++start;
    }
}

template <typename T>
void PmergeMe::merge_insert(T &container, int level)
{
    typedef typename T::iterator it;
    int pairs = container.size() / level;
    if (pairs < 2)
        return;
    
    bool is_odd = (pairs % 2 == 1);
    it start = container.begin();
    it last = next(start, level * pairs);
    it end = last;
    
    if (is_odd)
        end = next(last, -level);
    
    int jump = 2 * level;
    it i = start;
    while (i != end) {
        it first_node = next(i, level - 1);
        it second_node = next(i, jump - 1);
        PmergeMe::comps++;
        if (*second_node > *first_node)
            swap_pairs(first_node, level);
        i = next(i, jump);
    }
    
    merge_insert(container, level * 2);
    
    std::list<it> main;
    std::list<it> pend;
    
    main.push_back(next(container.begin(), level - 1));
    main.push_back(next(container.begin(), level * 2 - 1));
    
    for (int j = 4; j <= pairs; j += 2) {
        pend.push_back(next(container.begin(), level * (j - 1) - 1));
        main.push_back(next(container.begin(), level * j - 1));
    }
    
    if (is_odd)
        pend.push_back(next(end, level - 1));
    
    int prev_jacob = jacobsthal_value(2);
    int inserted = 0;
    int j = 2;
    
    while (true) {
        int curr_jacob = jacobsthal_value(j + 1);
        int diff = curr_jacob - prev_jacob;
        
        if (diff > static_cast<int>(pend.size()))
            break;
        
        typename std::list<it>::iterator pend_it = pend.begin();
        std::advance(pend_it, diff - 1);
        
        typename std::list<it>::iterator bound_it = main.begin();
        std::advance(bound_it, curr_jacob + inserted);
        
        int count = diff;
        while (count > 0) {
            typename std::list<it>::iterator idx = main.begin();
            for (; idx != bound_it; ++idx) {
                PmergeMe::comps++;
                if (**pend_it < **idx)
                    break;
            }
            main.insert(idx, *pend_it);
            pend_it = pend.erase(pend_it);
            if (pend_it == pend.begin())
                break;
            --pend_it;
            count--;
        }
        prev_jacob = curr_jacob;
        inserted += diff;
        ++j;
    }
    
    if (!pend.empty()) {
        typename std::list<it>::reverse_iterator rit = pend.rbegin();
        for (; rit != pend.rend(); ++rit) {
            typename std::list<it>::iterator bound_it = main.begin();
            std::advance(bound_it, main.size() - pend.size() + (is_odd ? 1 : 0));
            
            typename std::list<it>::iterator idx = main.begin();
            for (; idx != bound_it; ++idx) {
                PmergeMe::comps++;
                if (**rit < **idx)
                    break;
            }
            main.insert(idx, *rit);
        }
    }
    
    std::list<int> copy;
    for (typename std::list<it>::iterator mit = main.begin(); mit != main.end(); ++mit) {
        it pair_end = *mit;
        it pair_start = pair_end;
        std::advance(pair_start, -level + 1);
        for (int k = 0; k < level; ++k) {
            it val_it = pair_start;
            std::advance(val_it, k);
            copy.push_back(*val_it);
        }
    }
    
    it c_it = container.begin();
    for (typename std::list<int>::iterator v_it = copy.begin(); 
         v_it != copy.end() && c_it != container.end(); 
         ++v_it, ++c_it)
        *c_it = *v_it;
}

#endif