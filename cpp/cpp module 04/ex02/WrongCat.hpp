#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();

		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat &other);

		void	makeSound() const;

};

#endif