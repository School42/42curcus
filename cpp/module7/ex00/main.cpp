#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	std::cout << "before swapping: " << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swapping:" << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "before swapping:" << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after swapping:" << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	double e = 4.2;
	double f = 4.2;
	std::cout << "before swapping:" << "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "after swapping:" << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	// char g = 'g';
	// int h = 42;
	// std::cout << "before swapping:" << "g = " << g << ", h = " << h << std::endl;
	// swap(g, h);
	// std::cout << "after swapping:" << "g = " << g << ", h = " << h << std::endl;
	// std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	// std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
	return 0;
}