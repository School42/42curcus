#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Please run this program as : ./btc <filename>" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	BitcoinExchange exchange;
	exchange.calculatePrices(filename);
	return 0;
}