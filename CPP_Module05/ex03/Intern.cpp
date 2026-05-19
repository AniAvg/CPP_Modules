#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}


Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = 0;
	while (i < 3 && form_name != forms[i])
		i++;

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::FormNotFound();
	}
}

