#include "Character.hpp"

Character::Character()
: name("default"), size(0)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
	std::cout << GREEN << "Character default constructor called" << RESET << std::endl;
}

Character::Character(std::string _name)
: name(_name), size(0)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
	std::cout << GREEN << "Character " << name << " constructor called" << RESET << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < size; ++i)
	{
		if (inventory[i])
			delete inventory[i];
		inventory[i] = NULL;
	}
	std::cout << RED << "Character " << name << " destructor called" << RESET << std::endl;
}

Character::Character(const Character& other)
: name(other.name), size(other.size)
{
	std::cout << BLUE << "Character " << name << " copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character &other)
{
	std::cout << BLUE << "Character " << name << " copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		size = other.size;
		for (int i = 0; i < 4; ++i)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Cannot equip invalid materia" << std::endl;
		return ;
	}
	if (size < 4)
	{
		inventory[size] = m;
		size++;
	}
	else
	{
		std::cout << "Can't equip more materia, inventory of " << name << " is already full, deleting it" << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < size)
	{
		inventory[idx] = NULL;  // if you're the owner, delete the materia
		for (int i = idx; i < size - 1; ++i)
		{
			inventory[i] = inventory[i + 1];  // shift left
		}
		inventory[size - 1] = NULL;  // clear last
		size--;
	}
	else
	{
		std::cout << "Unable to unequip, idx is out of range! Size of inventory is " << size << " (note that idx is starting from 0)" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < size)
	{
		inventory[idx]->use(target);
	}
	else
	{
		std::cout << "Unable to use, idx is out of range! Size of inventory is " << size << " (note that idx is 0-3)" << std::endl;
	}
}
