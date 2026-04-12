#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixed_point;
		static const int	fractional_nb;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed	&operator=(const Fixed &other);

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	&operator++();
		Fixed	&operator--();

		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed &min(Fixed &nb_one, Fixed &nb_two);
		static const Fixed &min(const Fixed &nb_one, const Fixed &nb_two);

		static Fixed &max(Fixed &nb_one, Fixed &nb_two);
		static const Fixed &max(const Fixed &nb_one, const Fixed &nb_two);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};


std::ostream &operator<<(std::ostream &out, const Fixed &other);
