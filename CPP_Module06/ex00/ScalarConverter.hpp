#pragma once

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	void is_special_literal(const std::string& str);

	void print_char(const std::string& str);
	void print_int(const std::string& str);
	void print_float(const std::string& str);
	void print_double(const std::string& str);

	bool is_number(const std::string& str);

public:
	static void convert(const std::string& literal);
};
