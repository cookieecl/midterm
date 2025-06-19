#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class	PresidentialPardonForm : virtual public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&		operator=(const PresidentialPardonForm &other);
	
		std::string	getTarget() const;
		void		executeAction(Bureaucrat const & executor) const;

	private:
		const std::string	target;
};

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& presidentialPardonForm);

#endif