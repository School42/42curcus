#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::~Span() {}

Span::Span(const Span &other) {
	this->N = other.size();
	this->_vector = other._vector;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->N = other.size();
		this->_vector = other._vector;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_vector.size() < N)
		_vector.push_back(n);
	else
		throw SpanFullException();
}

void Span::addNumber(int start, int end, int size){
	srand(time(NULL));
	while (size > 0){
		int num = rand() % (end - start + 1) + start;
		try {
			addNumber(num);
		}
		catch (SpanFullException &e) {
			std::cout << e.what() << std::endl;
			break;
		}
		size--;
	}
}

unsigned int Span::shortestSpan() {
	if (_vector.size() < 2)
		throw SpanNotEnoughException();
	std::sort(_vector.begin(), _vector.end());
	int min = _vector[1] - _vector[0];
	for (unsigned int i = 1; i < _vector.size(); i++)
	{
		if (_vector[i] - _vector[i - 1] < min)
			min = _vector[i] - _vector[i - 1];
	}
	if (min < 0)
		min *= -1;
	return min;
}

unsigned int Span::longestSpan() {
	if (_vector.size() < 2)
		throw SpanNotEnoughException();
	std::sort(_vector.begin(), _vector.end());
	int max = _vector[_vector.size() - 1] - _vector[0];
	if (max < 0)
		max *= -1;
	return max;
}

unsigned int Span::size() const {
	return N;
}