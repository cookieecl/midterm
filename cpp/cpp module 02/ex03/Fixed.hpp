#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int _value);
		Fixed(const float _value);

		~Fixed();

		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed &other);

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& n1, Fixed& n2);
		static const Fixed&	min(const Fixed& n1, const Fixed& n2);
		static Fixed&		max(Fixed& n1, Fixed& n2);
		static const Fixed&	max(const Fixed& n1, const Fixed &n2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					value;
		static const int	fBits = 8;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif