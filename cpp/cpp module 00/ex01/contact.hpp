#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

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