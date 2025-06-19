#include "Animal.hpp"

Animal::Animal()
: type("unknown")
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string _type)
: type(_type)
{
	std::cout << GREEN << "Animal (" << type << ") constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED <<  "Animal (" << type << ") destructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other)
: type(other.type)
{
	std::cout << BLUE << "Animal (" << type << ") copy constructor called" << RESET << std::endl;
}

Animal&	Animal::operator=(const Animal &other)
{
	std::cout << BLUE << "Animal (" << type << ") copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

const std::string	Animal::getType() const
{
	return (type);
}

