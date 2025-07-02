/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:17 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:50:17 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal("Cat"), brain(new Brain)
{
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
	delete brain;
}

Cat::Cat(const Cat& other)
: Animal(other), brain(new Brain(*other.brain))
{
	std::cout << BLUE << "Cat copy constructor called" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	std::cout << BLUE << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meeooww!" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (brain);
}
