#pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();
		Intern &operator=(Intern const &src);
		AForm *makeForm(std::string const &formName, std::string const &target);
		class UnknownFormException;
};

class Intern::UnknownFormException : public std::exception
{
	public:
		const char *what() const throw() {
			return "Unknown form";
		}
};

#endif