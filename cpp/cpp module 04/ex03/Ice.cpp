/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:51:12 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:51:13 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{
	std::cout << GREEN << "Ice default constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << RED << "Ice destructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& other)
: AMateria(other)
{
	std::cout << BLUE << "Ice copy constructor called" << RESET << std::endl;
}

Ice&	Ice::operator=(const Ice &other)
{
	std::cout << BLUE << "Ice copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
		return (*this);
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria*	iceClone = new Ice(*this);
	return (iceClone);
}

void	Ice::use(ICharacter& target)
{
	std::string	targetName;
	try
	{
		targetName = target.getName();
	}
	catch(const std::exception& e)
	{
		std::cout << "Unable to shoots an ice bolt at an invalid target" << std::endl;
		return ;
	}
	std::cout << "Ice: \"* shoots an ice bolt at " << targetName << "* \"" << std::endl;
}
