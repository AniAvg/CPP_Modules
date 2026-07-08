#pragma once

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <iomanip>

#include <sstream>
#include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> database;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDatabase(std::string filename);
	void processInput(std::string filename);


private:
	bool is_valid_date(const std::string& date);
	bool is_valid_value(const std::string& value);
	double findRate(std::string date);
	std::string trim(const std::string& s);
};
