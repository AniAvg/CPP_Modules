#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	void is_special_literal(const std::string& str);

	static void print_char(int value);
	static void print_int(long value);
	static void print_float(float value);
	static void print_double(double value);

	static void convert_from_char(const std::string& literal);
	static void convert_from_int(const std::string& literal);
	static void convert_from_float(const std::string& literal);
	static void convert_from_double(const std::string& literal);

	bool is_number(const std::string& str);

public:
	static void convert(const std::string& literal);
};
