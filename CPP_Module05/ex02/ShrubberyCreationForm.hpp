#pragma once

#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(std::string& target);
	ShrubberyCreationForm& operator=(conat ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
};