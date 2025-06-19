#include "contact.hpp"

Contact::Contact()
{
    inputPrompt[0] = "Enter first name: ";
    inputPrompt[1] = "Enter last name: ";
    inputPrompt[2] = "Enter nickname: ";
    inputPrompt[3] = "Enter phone number: ";
    inputPrompt[4] = "Enter darkest secret: ";
}

void	Contact::init()
{
	std::cout << "Fill up the fields of the contact!" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		while (1)
		{
			std::cout << inputPrompt[i];

			if (!std::getline(std::cin, fields[i]))
			{
				throw std::runtime_error("EOF");
			}

			fields[i] = trimWhiteSpaces(fields[i]);
			if (inputCheck(i))
			{
				break ;
			}
		}
	}
}

void	Contact::printInfoFull()
{
	std::cout << "First name    : " << fields[0] << std::endl;
	std::cout << "Last name     : " << fields[1] << std::endl;
	std::cout << "Nickname      : " << fields[2] << std::endl;
	std::cout << "Phone number  : " << fields[3] << std::endl;
	std::cout << "Darkest Secret: " << fields[4] << std::endl;
}

void	Contact::printInfoPreview()
{
	for (int i = 0; i < 3; ++i)
	{
		int fieldLen = fields[i].length();
		if (fieldLen > 10)
		{
			std::cout << fields[i].substr(0, 9) << ".";
		}
		else
		{
			std::cout << fields[i].substr(0, fieldLen);
			for (int j = 0; j < 10 - fieldLen; ++j)
			{
				std::cout << " ";
			}
		}
		if (i != 2)
			std::cout << " | ";
	}
	std::cout << std::endl;
}

int	Contact::inputCheck(int i)
{
	if (fields[i].empty())
	{
		std::cout << "Field can't be empty" << std::endl;
	}
	else if ((i == 0 || i == 1) && !validateName(fields[i]))
	{
		std::cout << "Invalid name!" << std::endl;
	}
	else if (i == 3 && !validateNumber(fields[i]))
	{
		std::cout << "Invalid number!" << std::endl;
	}
	else
	{
		return (1);
	}
	return (0);
}

int	Contact::validateName(const std::string& name)
{
	for (int i = 0; i < name.length(); ++i)
	{
		if (!isalpha(name[i]) && name[i] != ' ')
			return (0);
		else if (i == 0 && name[i] == ' ')
			return (0);
		else if (name[i] == ' ' && name[i - 1] == ' ')
			return (0);
	}
	return (1);
}

int	Contact::validateNumber(const std::string& n)
{
	for (int i = 0; i < n.length(); ++i)
	{
		if (!isdigit(n[i]))
			return (0);
	}
	return (1);
}

std::string	Contact::trimWhiteSpaces(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return "";

	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	return (str.substr(start, end - start + 1));
}
