#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


class Span
{
private:
	unsigned int N;
	std::vector<int> numbers;
public:
	Span();
	Span(const Span& other);
	Span(unsigned int N);
	Span& operator=(const Span& other);
	~Span();

	class SpanFullException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Span is full");
		}
	};
	class NotEnoughNumbers : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Not enough numbers to find a span");
		}
	};

	void addNumber(int nb);

	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
	void addNumbersRange(Iterator begin, Iterator end)
	{
		if (numbers.size() + std::distance(begin, end) > N)
			throw SpanFullException();
		while (begin != end)
		{
			numbers.push_back(*begin);
			++begin;
		}
	}
};

