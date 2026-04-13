#include "Point.hpp"

Point::Point() : x(0), y(0)
{}


Point::Point(const float nb1, const float nb2) : x(nb1), y(nb2)
{}

Point::Point(const Point& other) : x(other.x), y(other.y)
{}


Point& Point::operator=(const Point &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

Point::~Point()
{}


const Fixed&	Point::get_x() const
{
	return (x);
}

const Fixed&	Point::get_y() const
{
	return (y);
}

