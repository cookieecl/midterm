/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:21:25 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/08 14:54:04 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(int diamondTrap);
		virtual ~FragTrap();

		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap &other);

		void	highFivesGuys(void);

	private:


};

#endif