#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		virtual ~ClapTrap();

		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap &other);

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		int				getHitPoints();
		int				getEnergyPoints();

	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDmg;

};

#endif