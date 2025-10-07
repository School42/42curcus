#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
	(void)src;
	return (*this);
}

void convert_char(std::string input) {
	char c = static_cast<char>(input[0]);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convert_int(std::string input) {
	std::stringstream ss(input);
	int i = 0;
	ss >> i;
	if (!(i >= 32 && i <= 126)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convert_float(std::string input) {
	double d = atof(input.c_str());
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);
	std::string float_tail = (f - i == 0) ? ".0f" : "f";
	std::string double_tail = (d - i == 0) ? ".0" : "";
	if (!(i >= 32 && i <= 126)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << float_tail << std::endl;
	std::cout << "double: " << d << double_tail << std::endl;
}

void convert_double(std::string input) {
	double d = atof(input.c_str());
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);
	std::string float_tail = (f - i == 0) ? ".0f" : "f";
	std::string double_tail = (d - i == 0) ? ".0" : "";
	if (!(i >= 32 && i <= 126)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << float_tail << std::endl;
	std::cout << "double: " << d << double_tail << std::endl;
}

void convert_nanf(std::string input) {
	(void)input;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void convert_error(std::string input) {
	(void)input;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string input) {
	std::string type;
	if (input.compare("-inf") == 0 || input.compare("+inf") == 0 || input.compare("nan") == 0 || input.compare("nanf") == 0 || input.compare("-inff") == 0 || input.compare("+inff") == 0) {
		type = "nanf";
	}
	else if (input.length() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == '.' || input[0] == 'f')) {
		type = "char";
	}
	else if (input.find_first_not_of("+-0123456789") == std::string::npos) {
		type = "int";
	}
	else if (input.find_first_not_of("+-0123456789.") == std::string::npos) {
		if (input.find_first_of(".") != input.find_last_of(".") || isdigit(input[input.find_first_of(".") + 1]) == false || input.find_first_of(".") == 0) {
			type = "error";
		} else {
			type = "double";
		}
	}
	else if (input.find_first_not_of("+-0123456789.f") == std::string::npos) {
		if (input.find_first_of("f") != input.find_last_of("f") ||
			input.find_first_of(".") != input.find_last_of(".") || isdigit(input[input.find_first_of(".") + 1]) == false || 
			input.find_first_of(".") == 0 || input.find_first_of("f") - input.find_first_of(".") == 1 ||
			input[input.find_first_of("f") + 1] != '\0') {
			type = "error";
		} else {
			type = "float";
		}
	}
	else if ((input.length() == 1 && std::isprint(input[0])) || 
		(input.length() == 1 && std::isalpha(input[0]))) {
		type = "char";
	}
	else {
		type = "error";
	}
	std::string types[] = {"char", "int", "float", "double", "nanf", "error"};
	for (int i = 0; i < 6; i++)
	{
		if (type == types[i])
		{
			switch (i)
			{
			case 0:
				convert_char(input);
				break;
			case 1:
				convert_int(input);
				break;
			case 2:
				convert_float(input);
				break;
			case 3:
				convert_double(input);
				break;
			case 4:
				convert_nanf(input);
				break;
			default:
				convert_error(input);
				break;
			}
		}
	}
}