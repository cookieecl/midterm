#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static const int	fBits = 8;
};

#endif