/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:51:04 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:51:04 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor called" << RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& other)
: AMateria(other)
{
	std::cout << BLUE << "Cure copy constructor called" << RESET << std::endl;
}

Cure&	Cure::operator=(const Cure &other)
{
	std::cout << BLUE << "Cure copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria*	cureClone = new Cure(*this);
	return (cureClone);
}

void	Cure::use(ICharacter& target)
{
	std::string	targetName;
	try
	{
		targetName = target.getName();
	}
	catch(const std::exception& e)
	{
		std::cout << "Unable to heal an invalid target" << std::endl;
		return ;
	}
	std::cout << "Cure: \"* heals " << targetName << "'s wounds *\"" << std::endl;
}
