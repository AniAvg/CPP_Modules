#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}



void ScalarConverter::is_special_literal(const std::string& str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "nan"
		|| str == "+inf" || str == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nan" || str == "nanf")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else
		{
			if (str[0] == '+')
			{
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			else
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
		}
	}
}


void ScalarConverter::print_char(const std::string& str)
{
	long value = std::atol(str);
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(value))
		std::cout << "char: non printable" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

void ScalarConverter::print_int(const std::string& str)
{
	if (is_number(str))
	{
		long value = std::stol(str);
		if (value > std::numeric_limits<int>::max()
			|| value < std::numeric_limits<int>::min())
		{
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			int i = static_cast<int>(value);
			std::cout << "int: " << i << std::endl;
		}
	}
}

void ScalarConverter::print_float(const std::string& str)
{
	if (is_number(str))
	{
		float f = static_cast<float>(value);
		std::cout << "float: " << f << std::endl;

	}
}

void ScalarConverter::print_double(const std::string& str)
{
	if (is_number(str))
	{
		double d = static_cast<double>(value);
		std::cout << "double: " << d << std::endl;
	}
}



bool ScalarConverter::is_number(const std::string& str)
{
	int		i = 0;
	bool	dot  = false;

	if ((str[i] == '+' || str[i] == '-') && str.length() == 1)
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	int len = str.length();
	if (len > 0 && str[len - 1] == 'f')
		len--;
	while (i < len)
	{
		if (str[i] == '.')
		{
			if (dot || i + 1 >= len)
				return (false);
			dot = true;
			i++;
			continue;
		}
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void ScalarConverter::convert(const std::string& literal)
{
	is_special_literal(literal);
}
