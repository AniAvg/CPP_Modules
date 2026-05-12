#pragma once

#include <string>

class PresidentialPardonForm : public AForm
{
private:
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(conat PresidentialPardonForm& other);
	PresidentialPardonForm(std::string& target);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};