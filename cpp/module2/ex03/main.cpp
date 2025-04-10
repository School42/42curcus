#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point p(4, 4);

	std::cout << "Point inside? " << (bsp(a, b, c, p) ? "Yes" : "No") << std::endl;
	return 0;
}
