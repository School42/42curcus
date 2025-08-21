#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
	public:
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm();
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);
		friend std::ostream &operator<<(std::ostream &out, AForm const &src);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSignedException;
};

class AForm::GradeTooHighException : public std::exception {
	public:
		const char *what() const throw(){
			return "Grade too high";
		}
};

class AForm::GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade too low";
		}
};

class AForm::FormNotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form not signed";
		}
};

#endif