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

bool	Fixed::operator>(const Fixed& other) const
{
	return (value > other.value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (value < other.value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (value <= other.value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (value != other.value);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() + other.getRawBits()));
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() - other.getRawBits()));
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * other.getRawBits()) >> fBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->getRawBits() << fBits) / other.getRawBits());
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	setRawBits(value + 1);
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	setRawBits(value - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);

	setRawBits(value + 1);
	return (copy);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);

	setRawBits(value - 1);
	return (copy);
}


Fixed&	Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

int	Fixed::getRawBits(void) const
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

int	Fixed::toInt(void) const
{
	return (static_cast<int>(value >> fBits));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
