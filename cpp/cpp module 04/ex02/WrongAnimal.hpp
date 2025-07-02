/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:50:35 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:50:35 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string _type);
		virtual ~WrongAnimal();

		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal &other);

		void	makeSound() const;

		const std::string	getType() const;

	protected:
		std::string	type;

};

#endif