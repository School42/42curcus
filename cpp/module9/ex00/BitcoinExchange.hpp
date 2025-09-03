#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
#include <cctype>
#include <cstdlib>
#include <ctime>

class BitcoinExchange
{
	private:
		std::map<time_t, double> _data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange & operator=(const BitcoinExchange &copy);
		void	calculatePrices(std::string filename);
		void	exchange(std::string date, std::string value);
		std::map<time_t, double> getData() const;
};

#endif