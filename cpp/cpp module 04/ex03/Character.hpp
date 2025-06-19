#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	Character : public ICharacter
{
	public:
		Character();
		Character(std::string _name);
		virtual ~Character();

		Character(const Character& other);
		Character&	operator=(const Character &other);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		std::string	name;
		int			size;
		AMateria*	inventory[4];

};

#endif