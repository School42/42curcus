#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &src);
		friend std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
		class GradeTooHighException;
		class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too high";
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too low";
		}
};

#endif