#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span {
	private:
		std::vector<int> _vector;
		unsigned int N;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span& operator=(const Span &other);
		void addNumber(int n);
		void addNumber(int start, int end, int size);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		unsigned int size() const;
		class SpanFullException;
		class SpanEmptyException;
		class SpanNotEnoughException;
};

class Span::SpanFullException : public std::exception {
	public:
		const char* what() const throw() {
			return "Span is full";
		}
};

class Span::SpanEmptyException : public std::exception {
	public:
		const char* what() const throw() {
			return "Span is empty";
		}
};

class Span::SpanNotEnoughException : public std::exception {
	public:
		const char* what() const throw() {
			return "Not enough numbers";
		}
};

#endif