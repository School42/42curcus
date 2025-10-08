#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	this->_array = NULL;
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->_size = other.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other.size();
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size || index < 0)
		throw OutOfRangeException();
	return this->_array[index];
}