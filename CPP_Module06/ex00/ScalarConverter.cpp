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



/***************** CHAR *******************/
void ScalarConverter::print_char(int value)
{
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(value))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::convert_from_char(const std::string& literal)
{
	char c = literal[1];
	int value = static_cast<int>(c);
	print_char(value);
	// print_int();
	// print_float();

	// print_double();

}



/***************** INT ********************/
void ScalarConverter::print_int(long value)
{
	if (value > std::numeric_limits<int>::max()
			|| value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}
}

void ScalarConverter::convert_from_int(const std::string& literal)
{
	char* end;

	errno = 0;
	long value = std::strtol(literal.c_str(), &end, 10);
	if (errno == ERANGE)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (end == literal.c_str())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	while (*end)
	{
		if (!std::isspace(static_cast<unsigned char>(*end)))
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		end++;
	}
	print_int(value);
}


/***************** FLOAT *********************/
void ScalarConverter::print_float(float value)
{
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
		<< value << "f" << std::endl;
}

void ScalarConverter::convert_from_float(const std::string& literal)
{
	char* end;

	errno = 0;
	float value = std::strtof(literal.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
		if (end == literal.c_str())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (*end == 'f' || *end == 'F')
		end++;
	while (*end)
	{
		if (!std::isspace(static_cast<unsigned char>(*end)))
		{
			std::cout << "float: impossible" << std::endl;
			return ;
		}
		end++;
	}
	print_float(value);
}


/******************* DOUBLE ********************/
void ScalarConverter::print_double(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
		std::cout << "double: " << std::fixed << std::setprecision(1)
		<< value << std::endl;
}

void ScalarConverter::convert_from_double(const std::string& literal)
{
	char* end;

	errno = 0;
	double value = std::strtod(literal.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
		if (end == literal.c_str())
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	while (*end)
	{
		if (!std::isspace(static_cast<unsigned char>(*end)))
		{
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		end++;
	}
	print_double(value);
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
