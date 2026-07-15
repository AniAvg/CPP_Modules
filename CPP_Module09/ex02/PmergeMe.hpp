#pragma once

#include <iostream>

#include <climits>
#include <ctime>

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

	void mergeInsertVector(std::vector<int>& v);
	void mergeInsertDeque(std::deque<int>& d);

	void makePairsVector(const std::vector<int>& v,
		std::vector<std::pair<int, int> >& v_pairs, bool& has_odd, int& odd);
	void makePairsDeque(const std::deque<int>& d,
		std::deque<std::pair<int, int> >& d_pairs, bool& has_odd, int& odd);

	void insertPendingVector(std::vector<int>& mainChain,
		const std::vector<int>& pending, bool has_odd, int odd);
	void insertPendingDeque(std::deque<int>& mainChain,
		const std::deque<int>& pending, bool has_odd, int odd);


	void process();
};
