/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:49:11 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:49:11 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	Animal
{
	public:
		Animal();
		Animal(std::string _type);
		virtual ~Animal();

		Animal(const Animal& other);
		Animal&	operator=(const Animal &other);

		virtual void	makeSound() const;

		const std::string	getType() const;

	protected:
		std::string	type;

};

#endif