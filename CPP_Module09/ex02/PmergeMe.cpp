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




void PmergeMe::mergeInsertVector(std::vector<int>& v)
{
	if (v.size() <= 1)
		return ;

	std::vector< std::pair<int,int> > v_pairs;
	bool has_odd = false;
	int odd = 0;

	makePairsVector(v, v_pairs, has_odd, odd);


	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i < v_pairs.size(); i++)
	{
		mainChain.push_back(v_pairs[i].second);
		pending.push_back(v_pairs[i].first);
	}
	mergeInsertVector(mainChain);
	insertPendingVector(mainChain, pending, has_odd, odd);

	v = mainChain;
}

void PmergeMe::mergeInsertDeque(std::deque<int>& d)
{
	if (d.size() <= 1)
		return ;

	std::deque< std::pair<int, int> > d_pairs;
	bool has_odd = false;
	int odd = 0;

	makePairsDeque(d, d_pairs, has_odd, odd);

	std::deque<int> mainChain;
	std::deque<int> pending;


	for (size_t i = 0; i < d_pairs.size(); i++)
	{
		mainChain.push_back(d_pairs[i].second);
		pending.push_back(d_pairs[i].first);
	}
	mergeInsertDeque(mainChain);
	insertPendingDeque(mainChain, pending, has_odd, odd);

	d = mainChain;
}




void PmergeMe::makePairsVector(const std::vector<int>& v,
	std::vector< std::pair<int, int> >& v_pairs, bool& has_odd, int& odd)
{
	has_odd = false;
	odd = 0;
	v_pairs.clear();

	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		int first = v[i];
		int second = v[i + 1];

		if (first > second)
			std::swap(first, second);

		v_pairs.push_back(std::make_pair(first, second));
	}

	if (v.size() % 2)
	{
		has_odd = true;
		odd = v.back();
	}
}

void PmergeMe::makePairsDeque(const std::deque<int>& d,
	std::deque< std::pair<int, int> >& d_pairs, bool& has_odd, int& odd)
{
	has_odd = false;
	odd = 0;
	d_pairs.clear();

	for (size_t i = 0; i + 1 < d.size(); i +=2)
	{
		int first = d[i];
		int second = d[i + 1];

		if (first > second)
			std::swap(first, second);

		d_pairs.push_back(std::make_pair(first, second));
	}

	if (d.size() % 2)
	{
		has_odd = true;
		odd = d.back();
	}
}





void PmergeMe::insertPendingVector(std::vector<int>& mainChain,
				const std::vector<int>& pending, bool has_odd, int odd)
{
	for (size_t i = 0; i < pending.size(); i++)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);

		mainChain.insert(pos, pending[i]);
	}

	if (has_odd)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), odd);

		mainChain.insert(pos, odd);
	}
}

void PmergeMe::insertPendingDeque(std::deque<int>& mainChain,
			const std::deque<int>& pending, bool has_odd, int odd)
{
	for (size_t i = 0; i < pending.size(); i++)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);

		mainChain.insert(pos, pending[i]);
	}

	if (has_odd)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), odd);

		mainChain.insert(pos, odd);
	}
}





void PmergeMe::process()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::clock_t v_start = std::clock();
	mergeInsertVector(vector);
	std::clock_t v_end = std::clock();


	std::clock_t d_start = std::clock();
	mergeInsertDeque(deque);
	std::clock_t d_end = std::clock();



	double v_time = static_cast<double>(v_end - v_start) * 1000000.0 / CLOCKS_PER_SEC;
	double d_time = static_cast<double>(d_end - d_start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vector.size()
		<< " elements with std::vector : " << v_time << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size()
		<< " elements with std::deque : " << d_time << " us" << std::endl;
	// ...
}
