#include "PmergeMe.hpp"

static std::string validate_arg(std::string arg)
{
    if (arg[0] == '-')
        return "Negative numbers are not allowed";
    long nbr = strtol(arg.c_str(), NULL, 10);
    if (nbr == 0 && arg != "0")
        return "Non-number arguments not allowed";
    if (nbr > INT_MAX || errno == ERANGE)
        return "Too big arguments are not allowed";
    return "";
}

static std::string validate(int argc, char** argv)
{
    if (argc == 1)
        return "No arguments were provided";
    for (int i = 1; i < argc; i++)
    {
        std::string status = validate_arg(argv[i]);
        if (status != "")
            return status;
    }
    return "";
}

static std::vector<int> argv_to_vector(int argc, char** argv)
{
    std::vector<int> res;
    res.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

static std::deque<int> argv_to_deque(int argc, char** argv)
{
    std::deque<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

template <typename T> static bool is_sorted(const T& container)
{
    if (container.size() == 0 || container.size() == 1)
        return true;
    typename T::const_iterator end = container.end();
    std::advance(end, -1);
    for (typename T::const_iterator it = container.begin(); it != end; it++)
    {
        typename T::const_iterator next = it;
        std::advance(next, 1);
        if (*next < *it) {
            return false;
		}
    }
    return true;
}

int main(int argc, char** argv)
{
    PmergeMe pm;
	
    std::string status = validate(argc, argv);
    if (status != "")
    {
        std::cerr << "Error: " << status << "\n";
        return EXIT_FAILURE;
    }

    clock_t start_vec = clock();
    std::vector<int> vec = argv_to_vector(argc, argv);
    pm.sort_vec(vec);
    clock_t end_vec = clock();
    double time_elapsed_vec = (static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC) * 1e6;

	PmergeMe::nbr_of_comps = 0;
    clock_t start_deque = clock();
    std::deque<int> deque = argv_to_deque(argc, argv);
    pm.sort_deque(deque);
    clock_t end_deque = clock();
    double time_elapsed_deque = (static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC) * 1e6;

    if (!is_sorted(vec) || (int)vec.size() != (argc - 1))
	{
        std::cout << "Vector was not sorted properly.\n";
		return 1;
	}
    if (!is_sorted(deque) || (int)deque.size() != (argc - 1))
	{
        std::cout << "Deque was not sorted properly.\n";
		return 1;
	}

    std::cout << "Before: ";
	for (int i = 1; i < argc ; i++){
		std::cout << argv[i] << " ";
	}
	std::cout << "\n";
    std::cout << "After:  ";
	for (int i = 0; i < (int)vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << time_elapsed_vec << " us\n";
    std::cout << "Time to process a range of " << deque.size()
              << " elements with std::deque:  "  << time_elapsed_deque << " us\n";
	if (EXPLANATION) {
		std::cout << "Number of comparisons: " << PmergeMe::nbr_of_comps << '\n';
	}
	return 0;
}
