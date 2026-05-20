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


AForm* Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}



AForm* Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*forms[])(std::string) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	
	int i = 0;
	while (i < 3 && form_name != form_names[i])
		i++;

	if (i == 3)
		throw FormNotFound();

	std::cout << "Intern creates " << form_names[i] << std::endl;
	return ((this->*forms[i])(target));
}

