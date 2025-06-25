/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:37:07 by aputri-a          #+#    #+#             */
/*   Updated: 2025/06/22 17:48:04 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	handleEOF()
{
	std::cout << std::endl << "==============================" << std::endl;
	std::cout << "Thanks!" << std::endl;
}

std::string	toupperStr(const std::string& str)
{
	std::string result = str;
	for (int i = 0; i < static_cast<int>(result.length()); ++i)
	{
		result[i] = static_cast<char>(std::toupper(result[i]));
	}
	return (result);
}

void	printMenu()
{
	std::cout << "Commands to choose from:" << std::endl;
	std::cout << "[1] ADD (save a new contact)" << std::endl;
	std::cout << "[2] SEARCH (display a specific contact)" << std::endl;
	std::cout << "[3] EXIT (exit the program)" << std::endl;
	std::cout << "Enter a command: ";
}

int	runCommand(PhoneBook& phoneBook, const std::string& cmd)
{
	// std::string	cmd = toupperStr(inputCmd);
	try
	{
		if (cmd == "ADD")
		{
			phoneBook.addContact();
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (cmd == "EXIT")
		{
			handleEOF();
			return (1);
		}
		else
		{
            throw std::runtime_error("Invalid command");
		}
		return (0);
	}
	catch(const std::runtime_error& e)
	{
		throw ;
	}
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	std::cout << "========== Phone Book Program ==========" << std::endl;
	while(1)
	{
		printMenu();
		if (!std::getline(std::cin, cmd))
		{
			handleEOF();
			return (0);
		}
		try
		{
			if (runCommand(phoneBook, cmd) == 1)
				return (0);
		}
		catch(const std::runtime_error& e)
		{
			if (std::string(e.what()) == "Invalid command")
				std::cout << "Invalid command, please try again!" << std::endl;
			else
			{
				handleEOF();
				return (0);
			}
		}
		std::cout << std::endl;
	}
}
