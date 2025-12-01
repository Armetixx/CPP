#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cctype>

namespace
{
	template <typename Sequence>
	Sequence mergeInsertSort(const Sequence &input)
	{
		if (input.size() <= 1)
			return input;

		typedef typename Sequence::value_type Value;

		std::vector< std::pair<Value, Value> > pairs;
		typename Sequence::const_iterator it = input.begin();
		bool hasStraggler = false;
		Value straggler = 0;

		while (it != input.end())
		{
			Value first = *it++;
			if (it == input.end())
			{
				hasStraggler = true;
				straggler = first;
				break;
			}
			Value second = *it++;
			if (first < second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}

		Sequence mainChain;
		for (size_t i = 0; i < pairs.size(); ++i)
			mainChain.push_back(pairs[i].first);

		mainChain = mergeInsertSort(mainChain);

		std::vector<Value> pend;
		std::vector<Value> limits;
		std::vector<bool> used(pairs.size(), false);

		for (typename Sequence::const_iterator mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt)
		{
			Value maxValue = *mainIt;
			for (size_t j = 0; j < pairs.size(); ++j)
			{
				if (!used[j] && pairs[j].first == maxValue)
				{
					limits.push_back(maxValue);
					pend.push_back(pairs[j].second);
					used[j] = true;
					break;
				}
			}
		}

		Sequence sorted = mainChain;
		std::vector<size_t> limitPositions(limits.size());
		for (size_t i = 0; i < limitPositions.size(); ++i)
			limitPositions[i] = i;

		if (!pend.empty())
		{
			size_t insertIndex = limitPositions[0];
			typename Sequence::iterator limitIt = sorted.begin();
			std::advance(limitIt, insertIndex);
			typename Sequence::iterator insertPos = std::lower_bound(sorted.begin(), limitIt, pend[0]);
			sorted.insert(insertPos, pend[0]);
			for (size_t j = 0; j < limitPositions.size(); ++j)
			{
				if (limitPositions[j] >= insertIndex)
					++limitPositions[j];
			}

			size_t n = pend.size();
			size_t jacobPrev = 1;
			size_t jacobCurr = 3;
			std::vector<size_t> order;
			while (jacobPrev < n)
			{
				size_t limit = jacobCurr;
				if (limit > n)
					limit = n;
				while (limit > jacobPrev)
				{
					order.push_back(limit);
					--limit;
				}
				size_t tmp = jacobCurr;
				jacobCurr = jacobCurr + 2 * jacobPrev;
				jacobPrev = tmp;
			}

			for (size_t i = 0; i < order.size(); ++i)
			{
				size_t idx = order[i];
				if (idx == 0 || idx > n)
					continue;
				size_t pendIndex = idx - 1;
				size_t limitIndex = limitPositions[pendIndex];
				typename Sequence::iterator limit = sorted.begin();
				std::advance(limit, limitIndex);
				typename Sequence::iterator pos = std::lower_bound(sorted.begin(), limit, pend[pendIndex]);
				sorted.insert(pos, pend[pendIndex]);
				for (size_t j = 0; j < limitPositions.size(); ++j)
				{
					if (limitPositions[j] >= limitIndex)
						++limitPositions[j];
				}
			}
		}

		if (hasStraggler)
		{
			typename Sequence::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
			sorted.insert(pos, straggler);
		}

		return sorted;
	}
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

static bool isDigits(const std::string &value)
{
	if (value.empty())
		return false;
	for (size_t i = 0; i < value.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(value[i])))
			return false;
	}
	return true;
}

void PmergeMe::parseInput(int argc, char **argv)
{
	_vectorData.clear();
	_dequeData.clear();
	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);
		if (!isDigits(token))
			throw std::runtime_error("invalid");
		long value = std::strtol(token.c_str(), 0, 10);
		if (value <= 0 || value > INT_MAX)
			throw std::runtime_error("invalid");
		_vectorData.push_back(static_cast<int>(value));
		_dequeData.push_back(static_cast<int>(value));
	}
	if (_vectorData.empty())
		throw std::runtime_error("invalid");
}

static void printSequence(const std::string &label, const std::vector<int> &data)
{
	std::cout << label;
	for (size_t i = 0; i < data.size(); ++i)
	{
		std::cout << (i ? " " : "") << data[i];
	}
	std::cout << std::endl;
}

void PmergeMe::process(int argc, char **argv)
{
	parseInput(argc, argv);

	printSequence("Before: ", _vectorData);

	clock_t startVec = std::clock();
	std::vector<int> sortedVec = mergeInsertSort(_vectorData);
	clock_t endVec = std::clock();

	clock_t startDeque = std::clock();
	std::deque<int> sortedDeque = mergeInsertSort(_dequeData);
	clock_t endDeque = std::clock();

	printSequence("After: ", sortedVec);

	double vecTime = static_cast<double>(endVec - startVec) * 1000000.0 / CLOCKS_PER_SEC;
	double dequeTime = static_cast<double>(endDeque - startDeque) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
