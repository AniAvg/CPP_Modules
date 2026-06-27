#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{}

BitcoinExchange::~BitcoinExchange()
{}




void BitcoinExchange::loadDatabase(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error could not open database.");

	std::string line;
	getline(file, line);

	while (getline(file, line))
	{
		size_t comma = line.find(',');
		
		std::string date = line.substr(0, comma);
		double rate = atof(line.substr(comma + 1).c_str());

		database[date] = rate;
	}
}
