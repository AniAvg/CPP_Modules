#pragma once

#include <string>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();

	void performAction() const;
};
