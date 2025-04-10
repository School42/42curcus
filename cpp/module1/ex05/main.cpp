#include "Harl.hpp"

int main() {
	Harl test;
	test.complain("debug");
	test.complain("info");
	test.complain("warning");
	test.complain("error");
	test.complain("default");
	return (0);
}