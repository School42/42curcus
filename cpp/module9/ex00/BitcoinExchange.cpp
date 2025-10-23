#include "BitcoinExchange.hpp"

int	ft_stoi(std::string str) {
	std::stringstream ss(str);
	int result;
	ss >> result;
	return result;
}

double ft_stod(std::string str) {
	std::stringstream ss(str);
	double result;
	ss >> result;
	return result;
}

time_t dateToTimeT(std::string date) {
	struct tm tm = {};
	char *result = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (result == NULL)
	{
		return -1;
	}
	if (tm.tm_year < 0 || tm.tm_mon < 0 || tm.tm_mday < 0)
	{
		return -1;
	}
	return mktime(&tm);
}

std::string timeTToDate(time_t time) {
	struct tm *tm = localtime(&time);
	std::ostringstream ss;
	ss << tm->tm_year + 1900 << "-" << tm->tm_mon + 1 << "-" << tm->tm_mday;
	return ss.str();
}

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

bool validateDate(std::string date) {
	if (date.empty())
		return false;
	std::list<std::string> tokens;
	std::stringstream ss(date);
	std::string token;
	while (ss >> token) {
		tokens.push_back(token);
	}
	if (tokens.size() > 1)	{
		return false;
	}
	std::list<std::string> dateTokens;
	std::stringstream ss2(*tokens.begin());
	std::string token2;
	while (std::getline(ss2, token2, '-')) {
		dateTokens.push_back(token2);
	}
	if (dateTokens.size() != 3)
		return false;
	std::list<std::string>::iterator it = dateTokens.begin();
	int year = ft_stoi(*it);
	int month = ft_stoi(*(++it));
	int day = ft_stoi(*(++it));
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || (month == 2 && day > 29 && isLeapYear(year) == false) || year < 1)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	} else if (month == 2) {
		if (day > 29 || (day > 28 && isLeapYear(year) == false))
			return false;
	} else {
		if (day > 31)
			return false;
	}
	return true;
}

bool validateValue(std::string value) {
	double val = ft_stod(value);
	if (val < 0)
		return false;
	return true;
}

float ft_stof(std::string str) {
	std::stringstream ss(str);
	float result;
	ss >> result;
	return result;
}

bool validateValueForExchange(std::string value) {
	float val = ft_stof(value);
	if (val < 0) {
		std::cout << "Error: Not a positive number." << std::endl;
		return false;
	}
	if (val > 1000) {
		std::cout << "Error: Too large a number." << std::endl;
		return false;
	}
	return true;
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	if (!file) {
		std::cerr << "Error: Could not open file" << std::endl;
		return;
	}

	std::string line;
	std::list<std::string> lines;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	file.close();

	std::map<time_t, double> data;
	std::list<std::string>::iterator it = lines.begin();
	it++;
	while (it != lines.end()) {
		std::stringstream ss(*it);
		std::string date;
		std::string value;
		std::getline(ss, date, ',');
		std::getline(ss, value);
		if (validateDate(date) == false || validateValue(value) == false) {
			std::cout << "Error: Invalid date or value" << std::endl;
			it++;
			continue;
		}
		data[dateToTimeT(date)] = ft_stod(value);
		it++;
	}
	this->_data = data;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		this->_data = copy.getData();
	}
	return *this;
}

void BitcoinExchange::calculatePrices(std::string filename) {
	std::ifstream file(filename.c_str());
	if (!file) {
		std::cerr << "Error: Could not open file" << std::endl;
		return;
	}
	std::string line;
	std::list<std::string> lines;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	std::list<std::string>::iterator it = lines.begin();
	it++;
	while (it != lines.end()) {
		std::stringstream ss(*it);
		std::string date;
		std::string value;
		std::getline(ss, date, '|');
		std::getline(ss, value);
		exchange(date, value);
		it++;
	}
}

void BitcoinExchange::exchange(std::string date, std::string value) {
	std::map<time_t, double>::iterator it = this->_data.end();
	// std::cout << "date: " << date << " value: " << value << std::endl;
	if (date.empty()) {
		std::cout << "Error: Missing date : ";
		if (!value.empty()) {
			std::cout << value;
		}
		std::cout << std::endl;
		return;
	}
	if (value.empty()) {
		std::cout << "Error: Missing value : ";
		if (!date.empty()) {
			std::cout << date;
		}
		std::cout << std::endl;
		return ;
	}
	if (validateDate(date) == false) {
		std::cout << "Error: Invalid date : " << date << std::endl;
		return;
	}
	if (validateValueForExchange(value) == false) {
		return;
	}
	time_t time = dateToTimeT(date);
	double val;
	if (this->_data.find(time) != this->_data.end()) {
		val = this->_data[time];
		std::cout << date << " => " << value << " = " << val * ft_stod(value) << std::endl;
		return;
	}
	it--;
	while (it->first > time && it != this->_data.begin()) {
		it--;
	}
	if (it->first > time) {
		std::cout << "Error: Date not found : " << date << std::endl;
		return;
	}
	val = it->second;
	std::cout << date << " => " << value << " = " << val * ft_stod(value) << std::endl;
}

std::map<time_t, double> BitcoinExchange::getData() const {
	return this->_data;
}