#pragma once

#include <iostream>
#include <map>
#include <stirng>

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

private:
	bool is_valid_date(std::stirng date);
	bool is_valid_value(std::string value);
};
