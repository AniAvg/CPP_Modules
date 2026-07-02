#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{}

BitcoinExchange::~BitcoinExchange()
{}



bool BitcoinExchange::is_valid_date(std::stirng date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)

	if (month == 2)
	{
		if ((leap && day > 29) || (!leap && day > 28))
			return false;
	}
	else if( ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
        return false;
	else if (day > 31)
		return false;
	if (day < 1)
		return false;
	return true;
}

bool BitcoinExchange::is_valid_value(std::string value)
{}




double BitcoinExchange::findRate(std::string date)
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

void BitcoinExchange::processInput(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	getline(file, line);

	while (getline(file, line))
	{
		size_t pos = line.find('|');
		
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line  << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pos));
		std::string str_value = trim(line.substr(pos + 1));

		if (!is_valid_date(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = atof(str_value.c_str());

		if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = findRate(date);

        std::cout << date << " => " << value << " = " << value * rate
        << std::endl;
    }
}
