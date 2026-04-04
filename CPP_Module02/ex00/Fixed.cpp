#include "Fixed.hpp"


const int Fixed::fractional_nb = 8;

Fixed::Fixed()
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// copy constructor
// copy assignment operator overload


int	Fixed::getRawBits(void) const
{}

void	Fixed::setRawBits(int const raw)
{}
