#include "Fixed.hpp"


const int Fixed::fractional_nb = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point = other.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point = other.fixed_point;
	return (*this);
}


int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}


///////////////////////////////////
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = n << fractional_nb;
}


Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(n * (1 << fractional_nb));
}



float	Fixed::toFloat(void) const
{
	return ((float)fixed_point / (float)(1 << fractional_nb));
}

int		Fixed::toInt(void) const
{
	return ((int)fixed_point / (int)(1 << fractional_nb));
}



std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}
