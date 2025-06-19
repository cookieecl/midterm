#include "Fixed.hpp"

Fixed::Fixed()
: value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value)
{
	std::cout << "Int constructor called" << std::endl;
	value = _value << fBits;
}

Fixed::Fixed(const float _value)
{
	std::cout << "Float constructor called" << std::endl;
	value = static_cast<int>(roundf(_value * (1 << fBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
: value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		value = other.value;
	}
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << fBits));
}

int		Fixed::toInt(void) const
{
	return (static_cast<int>(value >> fBits));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
