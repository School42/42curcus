#pragma once
#ifndef PRESIDENTIAL_PARDOM_FORM_HPP
#define PRESIDENTIAL_PARDOM_FORM_HPP

#include "AForm.hpp"

class PresidentialPardomForm : public AForm {
	private:
		std::string target;
	public:
		PresidentialPardomForm();
		PresidentialPardomForm(std::string const &target);
		PresidentialPardomForm(PresidentialPardomForm const &other);
		~PresidentialPardomForm();
		PresidentialPardomForm &operator=(PresidentialPardomForm const &other);
		void execute(Bureaucrat const &executor) const;
};

#endif