#include "easyfind.hpp"
#include <vector>
#include <list>

int	main()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(8);
	v.push_back(6);
	v.push_back(1);
	v.push_back(9);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 9);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		std::vector<int>::iterator it = easyfind(v, 2);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::list<int> l;
	l.push_back(90);
	l.push_back(80);
	l.push_back(10);

	try
	{
		std::list<int>::iterator it = easyfind(l, 80);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
