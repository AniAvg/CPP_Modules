#include "Span.hpp"

Span::Span() : N(0)
{}

Span::Span(unsigned int N) : N(N)
{}


Span::Span(const Span& other) : N(other.N), numbers(other.numbers)
{ }


Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return (*this);
}

Span::~Span()
{}


void Span::addNumber(int nb)
{
	if (numbers.size() >= N)
		throw SpanFullException();
	numbers.push_back(nb);
}


int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw NotEnoughNumbers();

	std::vector<int> copy = numbers;
	std::sort(copy.begin(), copy.end());

	int shortest = copy[1] - copy[0];

	for (size_t i = 1; i < copy.size() - 1; i++)
	{
		int diff = copy[i + 1] - copy[i];
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}


int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw NotEnoughNumbers();

	std::vector<int>::const_iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());

	return (*max - *min);
}

