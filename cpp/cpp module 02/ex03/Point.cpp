#include "Point.hpp"

Point::Point()
: x(0), y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float _x, const float _y)
: x(_x), y(_y)
{

}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point& other)
: x(other.x), y(other.y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point&	Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

const Fixed&	Point::getX() const
{
	return (x);
}

const Fixed&	Point::getY() const
{
	return (y);
}
