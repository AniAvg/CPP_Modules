#pragma once

#include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(conat RobotomyRequestForm& other);
	RobotomyRequestForm(std::string& target);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};