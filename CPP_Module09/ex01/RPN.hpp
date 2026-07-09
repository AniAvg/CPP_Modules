#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

class RPN
{
private:
	std::stack<int> stack;

	bool is_digit(const std::string& s);
	bool is_operation(const std::string& s);
	int evaluate_operation(int a, int b, char op);

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	int evaluate(const std::string& expression);
};