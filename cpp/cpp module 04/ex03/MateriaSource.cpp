/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:51:25 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/08 19:08:18 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
: size(0)
{
	for (int i = 0; i < 4; ++i)
		materiaLib[i] = NULL;
	std::cout << GREEN << "MateriaSource default constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < size; ++i)
	{
		if (materiaLib[i])
			delete materiaLib[i];
		materiaLib[i] = NULL;
	}
	std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
: size(other.size)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.materiaLib[i])
			materiaLib[i] = other.materiaLib[i]->clone();
		else
			materiaLib[i] = NULL;
	}
	std::cout << BLUE << "MateriaSource copy constructor called" << RESET << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << BLUE << "MateriaSource copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		size = other.size;
		for (int i = 0; i < 4; ++i)
		{
			if (materiaLib[i])
				delete materiaLib[i];
			if (other.materiaLib[i])
				materiaLib[i] = other.materiaLib[i]->clone();
			else
				materiaLib[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Cannot learn invalid materia" << std::endl;
		return ;
	}
	if (size < 4)
	{
		materiaLib[size] = m;
		size++;
	}
	else
	{
		std::cout << "Materia library is full, can't learn any more materia, so materia " << m->getType() << " will be deleted"<< std::endl;
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < size; ++i)
	{
		if (materiaLib[i] && materiaLib[i]->getType() == type)
			return (materiaLib[i]->clone());
	}
	std::cout << "Cannot create materia as materia type " << type << " has not been learnt" << std::endl;
	return (0);
}

