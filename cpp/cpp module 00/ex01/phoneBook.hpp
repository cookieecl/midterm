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