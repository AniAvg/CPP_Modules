#pragma once

#include <algorithm>
#include <iostream>

class NotFoundException : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Value not found in container");
	}
};



template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw NotFoundException();
	return i;
}
