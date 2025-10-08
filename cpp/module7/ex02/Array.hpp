#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T> class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);
		T &operator[](unsigned int index) const;

		unsigned int size() const;
		class OutOfRangeException : public std::exception {
			public:
				const char *what() const throw() {
					return "Index out of range";
				}
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &src) {
	out << src.size();
	return out;
}

#endif