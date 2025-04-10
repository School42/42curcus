#include <iostream>
#include <fstream>
#include <string>

std::string replace_all(std::string line, const std::string &s1, const std::string &s2) {
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
	return line;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream inputFile(filename.c_str());
	if (!inputFile) {
		std::cerr << "Could not open input file : " << filename << std::endl;
		return 1;
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile) {
		std::cerr << "Could not create output file." << std::endl;
		inputFile.close();
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << replace_all(line, s1, s2) << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
