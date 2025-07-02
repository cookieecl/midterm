/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:21 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:50:22 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
: Animal("Dog"), brain(new Brain)
{
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
	delete brain;
}

Dog::Dog(const Dog& other)
: Animal(other), brain(new Brain(*other.brain))
{
	std::cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	std::cout << BLUE << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (brain);
}