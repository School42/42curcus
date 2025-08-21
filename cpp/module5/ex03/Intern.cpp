#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const &src)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	AForm *form;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			switch (i)
			{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			}
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	throw UnknownFormException();
}