#include "Point.hpp"

// triangle's area formula - (1/2) * (x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2))

static Fixed area(const Point &a, const Point &b, const Point &c) {
	Fixed result = (a.getX() * (b.getY() - c.getY()) +
	                b.getX() * (c.getY() - a.getY()) +
	                c.getX() * (a.getY() - b.getY())) / Fixed(2);

	if (result.toFloat() < 0)
		return result * Fixed(-1);
	return result;
}


bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed areaABC = area(a, b, c);
	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);

	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0) {
		std::cerr << "Not a triangle" << std::endl;
		return false;
	}

	return (areaPAB + areaPBC + areaPCA == areaABC);
}
