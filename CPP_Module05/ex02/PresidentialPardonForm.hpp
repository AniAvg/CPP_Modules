#pragma once

#include <string>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
private:
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	PresidentialPardonForm(std::string& target);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};
