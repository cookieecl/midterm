/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:42:12 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 15:20:16 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a =  " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "// Testing a > b //" << std::endl;
	std::cout << (a > b) << std::endl << std::endl;
	std::cout << "// Testing a < b //" << std::endl;
	std::cout << (a < b) << std::endl << std::endl;
	std::cout << "// Testing a >= b //" << std::endl;
	std::cout << (a >= b) << std::endl << std::endl;
	std::cout << "// Testing a < b //" << std::endl;
	std::cout << (a <= b) << std::endl << std::endl;
	std::cout << "// Testing a == b //" << std::endl;
	std::cout << (a == b) << std::endl << std::endl;
	std::cout << "// Testing a != b //" << std::endl;
	std::cout << (a != b) << std::endl << std::endl;

	std::cout << "// Set a to 1.25 //" << std::endl;
	a.setRawBits(320);

	std::cout << "// Set c to 2 //" << std::endl;
	Fixed c(2);
	
	std::cout << std::endl << "// Testing a + c //" << std::endl;
	std::cout << (a + c) << std::endl;
	std::cout << std::endl << "// Testing a - c //" << std::endl;
	std::cout << (a - c) << std::endl;
	std::cout << std::endl << "// Testing a * c //" << std::endl;
	std::cout << (a * c) << std::endl;
	std::cout << std::endl << "// Testing a / c //" << std::endl;
	std::cout << (a / c) << std::endl;

	std::cout << std::endl << "// Testing --a //" << std::endl;
	std::cout << "before --a: " << a << std::endl;
	std::cout << "during --a: " << --a << std::endl;
	std::cout << "after --a: " << a << std::endl;
	std::cout << std::endl << "// Testing a-- //" << std::endl;
	std::cout << "before a--: " << a << std::endl;
	std::cout << "during a--: " << a-- << std::endl;
	std::cout << "after a--: " << a << std::endl;

	std::cout << std::endl << "// Testing ++a //" << std::endl;
	std::cout << "before ++a: " << a << std::endl;
	std::cout << "during ++a: " << ++a << std::endl;
	std::cout << "after ++a: " << a << std::endl;
	std::cout << std::endl << "// Testing a++ //" << std::endl;
	std::cout << "before a++: " << a << std::endl;
	std::cout << "during a++: " << a++ << std::endl;
	std::cout << "after a++: " << a << std::endl;

	std::cout << std::endl << "// Testing max(a, c) //" << std::endl;
	std::cout << Fixed::max(a, c) << std::endl;

	std::cout << std::endl << "// Testing min(a, c) //" << std::endl;
	std::cout << Fixed::min(a, c) << std::endl;

	return (0);
}
