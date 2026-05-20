#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(std::string form_name, std::string target);

	AForm* createShrubbery(std::string target);
	AForm* createRobotomy(std::string target);
	AForm* createPresidential(std::string target);

	class FormNotFound : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Form not found";
		}
	};
};

