#include "Span.hpp"

Span::Span()
{
	N = 0;
}

Span::Span(const Span& other)
{
	N = other.N;
	numbers = other.numbers
}

Span::Span(unsigned int N) : N(N)
{}


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


int Span::shortestSpan()
{
	std::vector<int> copy = numbers;
	std::sort(copy.begin(), copy.end());

	int size = copy.size();

}


int Span::longestSpan()
{
	std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
	return (*max - *min);
}

