#pragma once

#include <climits>

#include <iostream>
#include <vector>
#include <deque>


class PmergeMe
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parsing(int argc, char **argv);


};
