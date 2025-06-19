#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	Brain
{
	public:
		Brain();
		~Brain();

		Brain(const Brain& other);
		Brain&	operator=(const Brain &other);

		void			addIdea(std::string newIdea);
		std::string		getIdea(int i);

	private:
		std::string	ideas[100];
		int			size;
};

#endif