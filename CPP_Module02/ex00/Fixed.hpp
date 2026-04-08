#pragma once

#include <iostream>


class	Fixed
{
	private:
		int	fixed_point;
		static const int fractional_nb;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
