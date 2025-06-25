/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:37:16 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 15:37:17 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		void		addContact();
		void		searchContact();

	private:
		void		saveContact(const Contact& newContact);
		void		printContactsPreview();

		Contact		contacts[8];
		int			totalContacts;
		int			oldestIndex;
};

#endif