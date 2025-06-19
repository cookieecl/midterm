#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const& _type)
: type(_type)
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
: type(other.type)
{
	std::cout << BLUE << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	std::cout << BLUE << "AMateria copy assignment operator called" << RESET << std::endl;
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (type);
}

