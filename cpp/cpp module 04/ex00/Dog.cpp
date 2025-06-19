#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other)
: Animal(other)
{
	std::cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	std::cout << BLUE << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}
