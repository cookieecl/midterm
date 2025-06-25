/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:28:08 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 16:28:09 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	zombieNum = 6;
	Zombie* horde = zombieHorde(zombieNum, "heap");

	for (int i = 0; i < zombieNum; ++i)
		horde[i].announce();

	delete[] horde;
	return (0);
}
