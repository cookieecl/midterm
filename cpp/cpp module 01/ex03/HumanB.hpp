/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:05:54 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 18:05:54 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string _name);
		~HumanB();
		void		attack();
		void		setWeapon(Weapon& newWeapon);

	private:
		std::string	name;
		Weapon*		weapon;

};

#endif