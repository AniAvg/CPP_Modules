#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	this->stack = other.stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->stack = other.stack;
	}
	return (*this);
}

RPN::~RPN() {}


bool RPN::is_digit(const std::string& s)
{
	if (s.length() == 1 && std::isdigit(s[0]))
		return true;
	else
		return false;
}

bool RPN::is_operation(const std::string& s)
{
	if (s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	return false;
}

int RPN::evaluate_operation(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	else
		throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string& expression)
{
	while (!stack.empty())
		stack.pop();
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (is_digit(token))
			stack.push(token[0] - '0');
		else if (is_operation(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error");

			int a = stack.top();
			stack.pop();

			int b = stack.top();
			stack.pop();

			stack.push(evaluate_operation(b, a, token[0]));
		}
		else
			throw std::runtime_error("Error");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");

	return stack.top();
}

