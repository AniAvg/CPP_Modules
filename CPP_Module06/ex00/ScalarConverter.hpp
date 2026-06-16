#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cerrno>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(const std::string& literal);
};


bool is_special_literal(const std::string& str);
void print_char(int value);
void print_int(long value);
void print_float(float value);
void print_double(double value);
void convert_from_char(const std::string& literal);
void convert_from_int(const std::string& literal);
void convert_from_float(const std::string& literal);
void convert_from_double(const std::string& literal);
bool is_number(const std::string& str);