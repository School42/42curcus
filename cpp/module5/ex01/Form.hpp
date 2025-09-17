#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
	public:
		Form();
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		Form(Form const &src);
		~Form();
		Form &operator=(Form const &src);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);
		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out, Form const &src);

class Form::GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too high";
		}
};

class Form::GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too low";
	}
};


#endif