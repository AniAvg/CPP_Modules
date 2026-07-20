#pragma once

#include <iostream>

#include <climits>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <algorithm>


class PmergeMe
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parsing(int argc, char **argv);

	std::vector<size_t> insertionOrder(size_t count) const;

	size_t binarySearchVector(const std::vector<int>& chain,
		size_t left, size_t right, int i) const;
	size_t binarySearchDeque(const std::deque<int>& chain,
		size_t left, size_t right, int i) const;


	void mergeInsertVector(std::vector<int>& v);
	void mergeInsertDeque(std::deque<int>& d);


	void process();
};
