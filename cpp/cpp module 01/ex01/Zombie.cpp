/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:28:10 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 16:28:11 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
: name("[name not set]")
{
	std::cout << "A zombie is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been deleted" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::assignName(std::string _name)
{
	name = _name;
}
