/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:05:58 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 18:05:58 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
