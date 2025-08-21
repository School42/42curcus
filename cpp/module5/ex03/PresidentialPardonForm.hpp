#pragma once
#ifndef PRESIDENTIAL_PARDOM_FORM_HPP
#define PRESIDENTIAL_PARDOM_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		void execute(Bureaucrat const &executor) const;
};

#endif