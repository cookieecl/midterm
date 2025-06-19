#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();

		Dog(const Dog& other);
		Dog&	operator=(const Dog &other);

		void	makeSound() const;
		Brain*	getBrain() const;

	private:
		Brain	*brain;

};

#endif