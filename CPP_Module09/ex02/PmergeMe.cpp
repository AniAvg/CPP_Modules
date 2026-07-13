#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->vector = other.vector;
	this->deque = other.deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->vector = other.vector;
		this->deque = other.deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}




void PmergeMe::parsing(int argc, char **argv)
{
	if (!argv || !*argv)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; i++)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (!std::isdigit(static_cast<unsigned char>(argv[i][j])))
			{
				throw std::runtime_error("Error");
			}
			j++;
		}

		char *end;
		long nb = std::strtol(argv[i], &end, 10);
		if (*end != '\0')
			throw std::runtime_error("Error");
		if (nb <= 0 || nb > INT_MAX)
			throw std::runtime_error("Error");

		vector.push_back(static_cast<int>(nb));
		deque.push_back(static_cast<int>(nb));
	}
}

