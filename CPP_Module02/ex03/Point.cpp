#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Point Default constructor called";
}


Point::Point(const float nb1, const float nb2) : x(nb1), y(nb2)
{}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    std::cout << "Point copy constructor called";
}


Point& Point::operator=(const Point &other)
{
	std::cout << "Point copy assignment operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

Point::~Point()
{
	std::cout << "Point destructor called";
}