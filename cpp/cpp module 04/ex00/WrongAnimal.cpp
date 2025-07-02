/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:49:24 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:49:24 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("unknown")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type)
: type(_type)
{
	std::cout << GREEN << "WrongAnimal (" << type << ") constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED <<  "WrongAnimal (" << type << ") destructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
: type(other.type)
{
	std::cout << BLUE << "WrongAnimal (" << type << ") copy constructor called" << RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << BLUE << "WrongAnimal (" << type << ") copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound??" << std::endl;
}

const std::string	WrongAnimal::getType() const
{
	return (type);
}
