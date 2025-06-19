
#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	assignName(std::string _name);

	private:
		std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif