#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

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


	class SpanNotFound : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("No span can be found");
		}
	};

	void addNumber(int nb);

	int shortestSpan();
	int longestSpan();

	template <typename Iterator>
	void addNumbersRange(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) >= N)
			throw SpanFullException();
		while (begin != end)
		{
			numbers.push_back(*begin);
			begin++;
		}
	}
};

