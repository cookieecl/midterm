/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:37:12 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 15:37:13 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook()
: totalContacts(0), oldestIndex(0)
{

}

void	PhoneBook::addContact()
{
	Contact	contact;

	try
	{
		contact.init();
	}
	catch(const std::exception& e)
	{
        throw std::runtime_error("EOF");
	}

	saveContact(contact);
}

void	PhoneBook::searchContact()
{
	std::string	indexChosen;

	if (totalContacts == 0)
	{
		std::cout << "No contacts to be displayed!" << std::endl;
		return ;
	}

	while (1)
	{
		printContactsPreview();
		std::cout << "Choose 1 - " << totalContacts << ": ";

		if (!std::getline(std::cin, indexChosen))
		{
			throw std::runtime_error("EOF");
		}
		if (indexChosen.length() == 1 && isdigit(indexChosen[0])
			&& indexChosen[0] - '0' <= totalContacts && indexChosen[0] - '0' > 0)
		{
			contacts[indexChosen[0] - '0' - 1].printInfoFull();
			break ;
		}
		else
		{
			std::cout << "Invalid choice, please try again!" << std::endl;
		}
	}
}

void	PhoneBook::saveContact(const Contact& newContact)
{
	if (totalContacts == 8)
	{
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	else
	{
		contacts[totalContacts] = newContact;
		totalContacts++;
	}
	std::cout << "New contact has been added" << std::endl;
}

void	PhoneBook::printContactsPreview()
{
	for (int i = 0; i < totalContacts; ++i)
	{
		std::cout << "[" << i + 1 << "]" << " | ";
		contacts[i].printInfoPreview();
	}
}
