#pragma once

#include <exception>
#include <stdexcept>

template <typename T> class Array
{
private:
	T* arr;
	unsigned int len;
public:
	Array();
	~Array();

	Array(unsigned int n);
	Array(const Array& other);

	Array& operator=(const Array& other);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;

	unsigned int size() const;
};

#include "Array.tpp"
