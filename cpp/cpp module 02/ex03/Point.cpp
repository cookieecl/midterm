/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:42:31 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 15:22:21 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (this != &other)
	{
		return (*this);
	}
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
