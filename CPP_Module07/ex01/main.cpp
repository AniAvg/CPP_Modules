#include "iter.hpp"
#include <string>


int	main()
{
	int arr1[] = {4, 5, 6, 2, -3};

	std::cout << "Original array: ";
	iter(arr1, 5, print<int>);
	std::cout << std::endl;

	iter(arr1, 5, decrement<int>);

	std::cout << "After decrement: ";
	iter(arr1, 5, print<int>);
	std::cout << std::endl;

	std::string arr2[] = {"Barev", "aziz", "jan"};

	std::cout << "Strings: ";
	iter(arr2, 3, print<std::string>);
	std::cout << std::endl;

	const double arr3[] = {3.4, 5.6, 1.2};

	std::cout << "Const doubles: ";
	iter(arr3, 3, print<double>);
	std::cout << std::endl;
	return 0;
}
