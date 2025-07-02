/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:49:13 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:49:13 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other)
: Animal(other)
{
	std::cout << BLUE << "Cat copy constructor called" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	std::cout << BLUE << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meeooww!" << std::endl;
}
