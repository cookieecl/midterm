/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:42:34 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 12:42:34 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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