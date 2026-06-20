#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* arr, const size_t len, void (*f)(F&))
{
	size_t i = 0;
	if (!arr || !f)
		return ;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T, typename F>
void iter(const T* arr, const size_t len, void (*f)(const F&))
{
	size_t i = 0;
	if (!arr || !f)
		return ;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T>
void print(const T& value)
{
	std::cout << value << " ";
}

template <typename T>
void decrement(T& value)
{
	value--;
}

