#pragma once

#include <iostream>
#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float nb1, const float nb2);
		Point(const Point& other);
		~Point();

		Point& operator=(const Point &other);
		const Fixed&	get_x() const;
		const Fixed&	get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
