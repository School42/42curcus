#include "PmergeMe.hpp"

bool is_positive_number(std::string str) {
    if (str.empty())
        return false;
    if (str[0] == '-')
        return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    std::stringstream ss(str);
    long result;
    ss >> result;
    
    if (result <= 0)
        return false;
    if (result > std::numeric_limits<int>::max())
        return false;
    
    return true;
}

std::list<std::string> split(std::string str, char delimiter) {
    std::list<std::string> result;
    std::string token;
    size_t start = 0;
    
    while (start < str.length() && str[start] == delimiter)
        start++;
    
    while (start < str.length()) {
        size_t end = str.find(delimiter, start);
        if (end == std::string::npos)
            end = str.length();
        
        token = str.substr(start, end - start);
        result.push_back(token);
        start = end + 1;
        
        while (start < str.length() && str[start] == delimiter)
            start++;
    }
    
    return result;
}

bool validateArg(std::string arg) {
    std::list<std::string> tokens = split(arg, ' ');
    if (tokens.empty())
        return false;
    
    std::list<std::string>::iterator it = tokens.begin();
    while (it != tokens.end()) {
        if (!is_positive_number(*it))
            return false;
        ++it;
    }
    return true;
}

bool validateInput(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        if (!validateArg(av[i]))
            return false;
    }
    return true;
}

std::list<int> argv_to_list(int ac, char **av) {
    std::list<int> result;
    for (int i = 1; i < ac; i++) {
        std::list<std::string> tokens = split(av[i], ' ');
        std::list<std::string>::iterator it = tokens.begin();
        while (it != tokens.end()) {
            result.push_back(atoi(it->c_str()));
            ++it;
        }
    }
    return result;
}

std::deque<int> list_to_deque(std::list<int> list) {
    std::deque<int> result;
    std::list<int>::iterator it = list.begin();
    while (it != list.end()) {
        result.push_back(*it);
        ++it;
    }
    return result;
}

template <typename T> 
bool is_sorted(const T &container) {
    if (container.empty() || container.size() == 1)
        return true;
    
    typename T::const_iterator it = container.begin();
    typename T::const_iterator next_it = it;
    ++next_it;
    
    while (next_it != container.end()) {
        if (*it > *next_it)
            return false;
        ++it;
        ++next_it;
    }
    return true;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Please run this program as : ./PmergeMe <numbers>" << std::endl;
        return 1;
    }
    
    if (!validateInput(ac, av)) {
        std::cerr << "Error" << std::endl;
        std::cerr << "Please enter only positive int numbers!!!" << std::endl;
        return 1;
    }
    
    PmergeMe pm;
    
    // Get original input for display
    std::list<int> original = argv_to_list(ac, av);
    
    // Create separate copies for list and deque
    std::list<int> list_int = argv_to_list(ac, av);
    std::deque<int> deque_int = list_to_deque(original);
    
    // Sort list and measure time
    PmergeMe::comps = 0;
    clock_t start_lst = clock();
    pm.sort_list(list_int);
    clock_t end_lst = clock();
    double time_lst = (double)(end_lst - start_lst) / CLOCKS_PER_SEC * 1000000;
    
    // Sort deque and measure time
    PmergeMe::comps = 0;
    clock_t start_deq = clock();
    pm.sort_deque(deque_int);
    clock_t end_deq = clock();
    double time_deq = (double)(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;
    
    // Verify sorting
    // if (!is_sorted(list_int)) {
    //     std::cerr << "Error" << std::endl;
    //     std::cerr << "The list is not sorted!!!" << std::endl;
    //     return 1;
    // }
    
    // if (!is_sorted(deque_int)) {
    //     std::cerr << "Error" << std::endl;
    //     std::cerr << "The deque is not sorted!!!" << std::endl;
    //     return 1;
    // }
    
    // Print results
    std::cout << "Before : ";
    std::list<int>::iterator it = original.begin();
    while (it != original.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "After  : ";
    it = list_int.begin();
    while (it != list_int.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << list_int.size() 
              << " elements with std::list  : " << time_lst << " us" << std::endl;
    std::cout << "Time to process a range of " << deque_int.size() 
              << " elements with std::deque : " << time_deq << " us" << std::endl;
    
    return 0;
}