#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->database = other.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->database = other.database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}




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
		if (comma == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
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
	if(line != "date | value")
		throw std::runtime_error("Error: title not found.");

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

		if (!is_valid_value(str_value))
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

		try
		{
			double rate = findRate(date);
			double result = value * rate;

			std::ostringstream oss;
			oss << std::fixed << std::setprecision(2) << result;

			std::cout << date << " => " << value << " = " << oss.str() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}



std::string BitcoinExchange::trim(const std::string& s)
{
	int i = 0;
	while (i < (int)s.length() && std::isspace((unsigned char)s[i]))
		i++;
	if (i == (int)s.length())
		return ("");
	int j = s.length() - 1;
	while (j >= i && std::isspace((unsigned char)s[j]))
		j--;
	return (s.substr(i, j - i + 1));
}


bool BitcoinExchange::is_valid_date(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string year_str = date.substr(0, 4);
	std::string month_str = date.substr(5, 2);
	std::string day_str = date.substr(8, 2);

	for (int i = 0; i < (int)year_str.length(); i++)
		if (!isdigit((unsigned char)year_str[i]))
			return false;
	for (int i = 0; i < (int)month_str.length(); i++)
		if (!isdigit((unsigned char)month_str[i]))
			return false;
	for (int i = 0; i < (int)day_str.length(); i++)
		if (!isdigit((unsigned char)day_str[i]))
			return false;

	int year = atoi(year_str.c_str());
	int month = atoi(month_str.c_str());
	int day = atoi(day_str.c_str());

	if (month < 1 || month > 12)
		return false;

	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

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

bool BitcoinExchange::is_valid_value(const std::string& value)
{
	std::stringstream ss(value);
	double number;
	char extra;

	if (!(ss >> number))
		return false;
	if (ss >> extra)
		return false;

	return true;
}



double BitcoinExchange::findRate(std::string date)
{
	std::map<std::string, double>::iterator it;

	it = database.lower_bound(date);

	if (it != database.end() && it->first == date)
		return (it->second);
	if (it == database.begin())
		throw std::runtime_error("Error: No earlier date.");
	--it;
	return (it->second);
}
