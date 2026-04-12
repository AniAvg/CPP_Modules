#include "Fixed.hpp"


const int Fixed::fractional_nb = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
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




// comparison operators
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->fixed_point > other.fixed_point);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->fixed_point < other.fixed_point);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->fixed_point >= other.fixed_point);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->fixed_point <= other.fixed_point);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->fixed_point == other.fixed_point);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->fixed_point != other.fixed_point);
}


//  arithmetic operators
Fixed	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other.fixed_point == 0)
		return (0);
	return (this->toFloat() / other.toFloat());
}



// increment/decrement operators
Fixed&	Fixed::operator++()
{
	(this->fixed_point)++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	(this->fixed_point)--;
	return (*this);
}


Fixed	Fixed::operator++(int)
{
	Fixed fix = *this;
	(this->fixed_point)++;
	return (fix);
}

Fixed	Fixed::operator--(int)
{
	Fixed fix = *this;
	(this->fixed_point)--;
	return (fix);
}


Fixed& Fixed::min(Fixed &nb_one, Fixed &nb_two)
{
	if (nb_one > nb_two)
		return (nb_two);
	else
		return (nb_one);
}

const Fixed& Fixed::min(const Fixed &nb_one, const Fixed &nb_two)
{
	if (nb_one > nb_two)
		return (nb_two);
	else
		return (nb_one);
}

Fixed& Fixed::max(Fixed &nb_one, Fixed &nb_two)
{
	if (nb_one > nb_two)
		return (nb_one);
	return (nb_two);
}

const Fixed& Fixed::max(const Fixed &nb_one, const Fixed &nb_two)
{
	if (nb_one > nb_two)
		return (nb_one);
	return (nb_two);
}
