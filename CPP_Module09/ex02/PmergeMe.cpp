#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	parsing(argc, argv);
}

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
	if (argc < 2)
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



/////////////////
///////////
////

std::vector<size_t> PmergeMe::insertionOrder(size_t count) const
{
	std::vector<size_t> order;
	if (count == 0)
		return order;

	order.push_back(0);
	if (count == 1)
		return order;

	std::vector<size_t> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() < count)
		jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

	size_t inserted = 1;
	for (size_t g = 2; g < jac.size() && inserted < count; g++)
	{
		size_t hi = jac[g];
		size_t lo = jac[g - 1];
		if (hi > count)
			hi = count;
		for (size_t idx = hi; idx > lo; idx--)
		{
			order.push_back(idx - 1);
			inserted++;
		}
	}
	return order;
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& chain, size_t left, size_t right, int i) const
{
	int value = vector[i];
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (vector[chain[mid]] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

size_t PmergeMe::binarySearchDeque(const std::deque<int>& chain, size_t left, size_t right, int i) const
{
	int value = deque[i];
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (deque[chain[mid]] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void PmergeMe::mergeInsertVector(std::vector<int>& indexes)
{
	size_t n = indexes.size();
	if (n <= 1)
		return;

	std::vector<int> larger;
	std::vector<int> smaller;
	larger.reserve(n / 2);
	smaller.reserve(n / 2);

	size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		int first_index = indexes[i];
		int second_index = indexes[i + 1];
		if (vector[first_index] > vector[second_index])
		{
			larger.push_back(first_index);
			smaller.push_back(second_index);
		}
		else
		{
			larger.push_back(second_index);
			smaller.push_back(first_index);
		}
	}

	bool hasStraggler = (n % 2 != 0);
	int straggler = hasStraggler ? indexes[n - 1] : 0;

	std::vector<int> originallarger = larger;
	mergeInsertVector(larger);

	std::vector<int> mainChain = larger;
	std::vector<int> index_pos(vector.size(), -1);
	for (size_t p = 0; p < mainChain.size(); p++)
		index_pos[mainChain[p]] = static_cast<int>(p);

	std::vector<size_t> order = insertionOrder(smaller.size());

	for (size_t oi = 0; oi < order.size(); oi++)
	{
		size_t k = order[oi];
		int loserId = smaller[k];
		int winnerId = originallarger[k];
		size_t bound = static_cast<size_t>(index_pos[winnerId]) + 1;

		size_t insertPos = binarySearchVector(mainChain, 0, bound, loserId);
		mainChain.insert(mainChain.begin() + insertPos, loserId);

		index_pos[loserId] = static_cast<int>(insertPos);
		for (size_t p = insertPos + 1; p < mainChain.size(); p++)
			index_pos[mainChain[p]] = static_cast<int>(p);
	}

	if (hasStraggler)
	{
		size_t insertPos = binarySearchVector(mainChain, 0, mainChain.size(), straggler);
		mainChain.insert(mainChain.begin() + insertPos, straggler);
	}

	indexes = mainChain;
}

void PmergeMe::mergeInsertDeque(std::deque<int>& indexes)
{
	size_t n = indexes.size();
	if (n <= 1)
		return;

	std::deque<int> larger;
	std::deque<int> smaller;

	size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		int first_index = indexes[i];
		int second_index = indexes[i + 1];
		if (deque[first_index] > deque[second_index])
		{
			larger.push_back(first_index);
			smaller.push_back(second_index);
		}
		else
		{
			larger.push_back(second_index);
			smaller.push_back(first_index);
		}
	}

	bool hasStraggler = (n % 2 != 0);
	int straggler = hasStraggler ? indexes[n - 1] : 0;

	std::deque<int> originallarger = larger;
	mergeInsertDeque(larger);

	std::deque<int> mainChain = larger;
	std::vector<int> index_pos(deque.size(), -1);
	for (size_t p = 0; p < mainChain.size(); p++)
		index_pos[mainChain[p]] = static_cast<int>(p);

	std::vector<size_t> order = insertionOrder(smaller.size());

	for (size_t oi = 0; oi < order.size(); oi++)
	{
		size_t k = order[oi];
		int loserId = smaller[k];
		int winnerId = originallarger[k];
		size_t bound = static_cast<size_t>(index_pos[winnerId]) + 1;

		size_t insertPos = binarySearchDeque(mainChain, 0, bound, loserId);
		mainChain.insert(mainChain.begin() + insertPos, loserId);

		index_pos[loserId] = static_cast<int>(insertPos);
		for (size_t p = insertPos + 1; p < mainChain.size(); p++)
			index_pos[mainChain[p]] = static_cast<int>(p);
	}

	if (hasStraggler)
	{
		size_t insertPos = binarySearchDeque(mainChain, 0, mainChain.size(), straggler);
		mainChain.insert(mainChain.begin() + insertPos, straggler);
	}

	indexes = mainChain;
}



void PmergeMe::process()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;


	std::clock_t v_start = std::clock();

	std::vector<int> vector_indexes(vector.size());
	for (size_t i = 0; i < vector_indexes.size(); i++)
		vector_indexes[i] = static_cast<int>(i);

	mergeInsertVector(vector_indexes);

	std::clock_t v_end = std::clock();

	std::clock_t d_start = std::clock();

	std::deque<int> deque_indexes(deque.size());
	for (size_t i = 0; i < deque_indexes.size(); i++)
		deque_indexes[i] = static_cast<int>(i);

	mergeInsertDeque(deque_indexes);

	std::clock_t d_end = std::clock();

	double v_time = static_cast<double>(v_end - v_start)
		* 1000000.0 / CLOCKS_PER_SEC;
	double d_time = static_cast<double>(d_end - d_start)
		* 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (size_t i = 0; i < vector_indexes.size(); i++)
		std::cout << vector[vector_indexes[i]] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vector.size()
		<< " elements with std::vector : " << v_time << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size()
		<< " elements with std::deque : " << d_time << " us" << std::endl;
}


