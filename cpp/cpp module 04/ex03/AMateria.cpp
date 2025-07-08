/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:45 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/08 16:11:44 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const& _type)
: type(_type)
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
: type(other.type)
{
	std::cout << BLUE << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	std::cout << BLUE << "AMateria copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (type);
}

