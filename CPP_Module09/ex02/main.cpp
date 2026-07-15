#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	try
	{
		PmergeMe p(argc, argv);
		p.process();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
