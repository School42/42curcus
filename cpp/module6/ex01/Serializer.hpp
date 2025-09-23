#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data {
	std::string name;
	size_t age;
} Data;

class Serializer {
	public:
		Serializer();
		~Serializer();
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &src);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif