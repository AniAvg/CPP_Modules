#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	arr = NULL;
	len = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}


template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n]();
	len = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	this->len = other.len;
	this->arr = new T[len];
	for (unsigned int i = 0; i < len; i++)
		this->arr[i] = other.arr[i];
}



template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* new_arr = new T[other.len]();
		for (unsigned int i = 0; i < other.len; ++i)
			new_arr[i] = other.arr[i];
		delete[] arr;
		arr = new_arr;
		len = other.len;
	}
	return *this;
}


template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= len)
		throw std::out_of_range("Array index out of range");
	return arr[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= len)
		throw std::out_of_range("Array index out of range");
	return arr[i];
}



template <typename T>
unsigned int Array<T>::size() const
{
	return len;
}


