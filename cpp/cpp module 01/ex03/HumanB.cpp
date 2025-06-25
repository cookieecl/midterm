/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:05:52 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 18:05:52 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
: name(_name)
{

}

HumanB::~HumanB()
{
	
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " is unable to attack without any weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}
