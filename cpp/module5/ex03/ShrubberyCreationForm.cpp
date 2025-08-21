#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

std::string ascii_tree() {
	std::string ascii_tree;
	ascii_tree = "	  _-_\n   /~~   ~~\\\n/~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
	return ascii_tree;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > 150)
			throw AForm::GradeTooLowException();
		if (executor.getGrade() < 0)
			throw AForm::GradeTooHighException();
		std::string filename = this->target + "_shrubbery";
		const char *filename_cstr = filename.c_str();
		std::ofstream my_file(filename_cstr);
		if (!my_file)
			throw std::runtime_error("Couldn't create the file");
		my_file << ascii_tree() << std::endl;
		my_file.close();
		std::cout << "ShrubberyCreationForm executed by " << executor.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}