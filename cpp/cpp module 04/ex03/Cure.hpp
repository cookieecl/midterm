#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	Cure : public AMateria
{
	public:
		Cure();
		~Cure();

		Cure(const Cure& other);
		Cure&	operator=(const Cure &other);

		AMateria*	clone() const;
		void		use(ICharacter& target);

	private:

};

#endif