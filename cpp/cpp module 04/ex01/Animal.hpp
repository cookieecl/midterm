#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class	Animal
{
	public:
		Animal();
		Animal(std::string _type);
		virtual ~Animal();

		Animal(const Animal& other);
		Animal&	operator=(const Animal &other);

		virtual void	makeSound() const;
		virtual Brain*	getBrain() const = 0;

		const std::string	getType() const;

	protected:
		std::string	type;

};

#endif