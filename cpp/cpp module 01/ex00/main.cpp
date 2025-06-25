/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:58:20 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 15:58:21 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* heapZombie = newZombie("heap");
	heapZombie->announce();

	randomChump("stack");
	delete heapZombie;
	return (0);
}
