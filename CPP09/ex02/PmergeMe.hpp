#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void process(int argc, char **argv);

private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;

	void parseInput(int argc, char **argv);
};

#endif
