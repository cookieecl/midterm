/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:01 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:50:02 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
: WrongAnimal(other)
{
	std::cout << BLUE << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &other)
{
	std::cout << BLUE << "WrongCat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		return (*this);
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meeooww!" << std::endl;
}
