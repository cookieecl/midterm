#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const float n1, const float n2);
		~Point();

		Point(const Point& other);
		Point&	operator=(const Point &other);

		const Fixed&	getX() const;
		const Fixed&	getY() const;

	private:
		const Fixed	x;
		const Fixed	y;

};

#endif