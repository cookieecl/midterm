#pragma once
#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		virtual ~MateriaSource();

		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource &other);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);

	private:
		AMateria*	materiaLib[4];
		int			size;

};

#endif