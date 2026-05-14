#pragma once

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();

	void performAction() const;
};
