#include "header.hpp"

void	handleEOF()
{
	std::cout << std::endl << "==============================" << std::endl;
	std::cout << "Thanks!" << std::endl;
	std::exit(0);
}

std::string	toupperStr(const std::string& str)
{
	std::string result = str;
	for (int i = 0; i < result.length(); ++i)
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

void	runCommand(PhoneBook& phoneBook, const std::string& inputCmd)
{
	std::string	cmd = toupperStr(inputCmd);

	try
	{
		if (cmd == "ADD" || cmd == "1")
		{
			phoneBook.addContact();
		}
		else if (cmd == "SEARCH" || cmd == "2")
		{
			phoneBook.searchContact();
		}
		else if (cmd == "EXIT" || cmd == "3")
		{
			handleEOF();
		}
		else
		{
            throw std::runtime_error("Invalid command");
		}
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
		}
		try
		{
			runCommand(phoneBook, cmd);
		}
		catch(const std::runtime_error& e)
		{
			if (std::string(e.what()) == "Invalid command")
				std::cout << "Invalid command, please try again!" << std::endl;
			else
				handleEOF();
		}
		std::cout << std::endl;
	}
}
