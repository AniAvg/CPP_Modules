#pragma once

class	Fixed
{
	private:
		int	fixed_point;
		static const int fractional_nb;
	public:
		Fixed();
		// copy constructor
		// copy assignment operator overload
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};