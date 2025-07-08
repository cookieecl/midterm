/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:21:19 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/08 14:48:16 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		virtual ~DiamondTrap();

		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap &other);

		void	attack(const std::string& target);
		void	whoAmI();

	private:
		std::string	name;

};

#endif