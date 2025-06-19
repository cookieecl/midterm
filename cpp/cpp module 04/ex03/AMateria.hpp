#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	ICharacter;

class	AMateria
{
	public:
		AMateria();
		AMateria(std::string const& _type);
		virtual ~AMateria();

		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria &other);

		std::string const&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target) = 0;

	protected:
		std::string	type;

};

#endif