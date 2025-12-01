#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;
	try
	{
		sorter.process(argc, argv);
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
