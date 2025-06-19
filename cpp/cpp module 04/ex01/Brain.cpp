#include "Brain.hpp"

Brain::Brain()
: size(0)
{
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
: size(other.size)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];	
	std::cout << BLUE << "Brain copy constructor called" << RESET << std::endl;
}

Brain&	Brain::operator=(const Brain &other)
{
	std::cout << BLUE << "Brain copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		size = other.size;
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::addIdea(std::string newIdea)
{
	if (size == 100)
	{
		std::cout << "Brain is full :(" << std::endl;
		return ;
	}
	
	ideas[size] = newIdea;
	std::cout << "New idea(" << newIdea << ") is added in index " << size << std::endl;
	size++;
}

std::string		Brain::getIdea(int i)
{
	if (i >= size || i < 0)
	{
		return ("");
	}
	return (ideas[i]);
}
