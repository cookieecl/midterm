#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
: type(_type)
{

}

Weapon::~Weapon()
{
	
}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}
