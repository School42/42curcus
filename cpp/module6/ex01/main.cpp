#include "Serializer.hpp"

int main() {
	Data *data = new Data;
	data->name = "John Doe";
	data->age = 42;
	uintptr_t serialized = Serializer::serialize(data);
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Age: " << deserialized->age << std::endl;
	delete data;
	return 0;
}