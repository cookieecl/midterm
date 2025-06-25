/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:36:53 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 17:49:45 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Contact
{
	public:
		Contact();
		void	init();
		void	printInfoFull();
		void	printInfoPreview();

	private:
		int			inputCheck(int i);
		int			validateName(const std::string& name);
		int			validateNumber(const std::string& n);
		std::string	trimWhiteSpaces(const std::string& str);
		std::string	inputPrompt[5];
		std::string	fields[5];
};

#endif